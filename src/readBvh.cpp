#include <fstream>
#include <iostream>
#include <algorithm>
#include "readBvh.h"
using namespace BVH;

void BvhFile::loadFile(string filePath)
{
    string line;
    vector<string> lines;
    // Joint *parentJoint = new Joint;
    // bool isEndSite = false;
    fileName = getFileName(filePath);
    bool isBvhfile = judgeFileType(filePath);

    if (!isBvhfile)
    {
        cerr << "the type of file is error!";
        return;
    }

    ifstream file; //打开文件
    file.open(filePath, ios::in);

    if (!file.good())
    {
        cerr << "ifstream open file error!\n";
        return;
    }
    loadFileState = true;
    while (getline(file, line)) //获取每一行数据
    {
        line.erase(std::remove_if(line.begin(), line.end(), &delSubstr), line.end());
        lines.push_back(line); //将每一行依次存入到 vector 中
    }
    file.close();
    line.shrink_to_fit();

    mapKeyword["ROOT"] = 1;
    mapKeyword["JOINT"] = 1;
    mapKeyword["End"] = 1;
    mapKeyword["OFFSET"] = 2;
    mapKeyword["CHANNELS"] = 3;
    mapKeyword["{"] = 4;
    mapKeyword["}"] = 4;
    mapKeyword["Frames"] = 5;
    mapKeyword["Frame"] = 6;
    vector<string> jointName;
    vector<string>::iterator it;
    for (it = lines.begin(); it != lines.end(); ++it)
    {
        vector<string> keyword = splitString(*it, " ");
        switch (mapKeyword.find(keyword[0])->second)
        {
        case 1:
            if (keyword[0] == "End")
            {
                keyword[1] = jointName[leftBracket - 1] + "EndSite";
            }
            jointName.push_back(setJointName(keyword));
            setEndSiteValue(jointName, keyword);
            break;
        case 2:
            setOffsetValue(jointName, keyword);
            break;
        case 3:
            setChannels(jointName, keyword);
            break;
        case 4:
            addChildrenJoint(jointName, keyword);
            break;
        case 5:
            numFrame = stoi(keyword[1]); // 总帧数
            numJoint = jointName.size(); // 关节总数
            break;
        case 6:
            frameDuartion = stod(keyword[2]);
            break;
        default:
            if (keyword[0].find(".") != string::npos)
            {
                setMotionValue(jointName, keyword);
            }
            break;
        }
    }
}

void BvhFile::resetData()
{
    motions.clear();
    mapJoint.clear();
    mapKeyword.clear();
    loadFileState = false; // 文件状态设置为未加载
    fileName.clear();
    numChannel = 0;
    numFrame = 0;
    frameDuartion = 0;
}

// 获取文件名字
string BvhFile::getFileName(string filePath)
{
    int index = filePath.find_last_of("/\\");
    return filePath.substr(index + 1);
}

// 判断文件类型是否为 BVH
bool BvhFile::judgeFileType(string filePath)
{
    int index = filePath.find_last_of(".");
    return (filePath.substr(index + 1) == "bvh");
}

// 删除读取的字符串中的特定字符
bool BvhFile::delSubstr(char c)
{
    switch (c)
    {
    case ',':
    case ':':
    case '\t':
        return true;
    default:
        return false;
    }
}

// 分割字符串
vector<string> BvhFile::splitString(const string &str, const string &pattern)
{
    vector<string> res;
    if (str == "")
        return res;

    string strs = str + pattern;

    size_t pos = strs.find(pattern);
    size_t size = strs.size();

    while (pos != string::npos)
    {
        string x = strs.substr(0, pos);
        res.push_back(x);
        strs = strs.substr(pos + 1, size);
        pos = strs.find(pattern);
    }
    return res;
}

// 写入关节名字
string BvhFile::setJointName(vector<string> keyword)
{
    mapJoint[keyword[1]] = *(new Joint);
    return keyword[1]; //返回关节名字
}

// 为关节添加子关节
void BvhFile::addChildrenJoint(vector<string> jointName, vector<string> keyword)
{
    if (keyword[0] == "{")
    {
        ++leftBracket;
        if (leftBracket - rightBracket > 1)
        {
            if (rightBracket != rightBracketLevel)
            {
                rightBracketLevel = rightBracket;
            }
            if (rightBracket == rightBracketLevel)
            {
                mapJoint[jointName[leftBracket - 2]].children[jointName[leftBracket - 1]] = (&(mapJoint[jointName[leftBracket - 1]]));
            }
            else
            {
                mapJoint[jointName[leftBracket - rightBracketLevel - 2]].children[jointName[leftBracket - 1]] = (&(mapJoint[jointName[leftBracket - 1]]));
            }
        }
    }
    if (keyword[0] == "}")
    {
        ++rightBracket;
    }
}

// 写入 OFFSET 数据
void BvhFile::setOffsetValue(vector<string> jointName, vector<string> keyword)
{
    for (int i = 1; i < keyword.size(); ++i)
    {
        mapJoint[jointName[leftBracket - 1]].offset[i - 1] = stod(keyword[i]);
    }
}

// 写入 CHANNELS 数据
void BvhFile::setChannels(vector<string> jointName, vector<string> keyword)
{
    for (int i = 2; i < keyword.size(); ++i)
    {
        mapJoint[jointName[leftBracket - 1]].channels[keyword[i]] = 0;
    }
}

// 写入 End Site 值
void BvhFile::setEndSiteValue(vector<string> jointName, vector<string> keyword)
{
    if (keyword[1].find("End") != string::npos)
    {
        mapJoint[jointName[leftBracket]].hasEndSite = true;
        ++numEndSite;
    }
}

// 写入 MOTION 值
void BvhFile::setMotionValue(vector<string> jointName, vector<string> keyword)
{
    int k = 0; // 用来辅助 i 读取 keyword 的数据
    for (int i = 0; i < 6; ++i)
    {
        mapJoint[jointName[0]].channels[rootChannels[i]] = stod(keyword[i]);
    }

    for (int j = 1; j < jointName.size(); j++)
    {

        if (mapJoint[jointName[j]].hasEndSite == false)
        {
            for (int i = 0; i < 3; ++i)
            {
                // i,k 用来读取 keyword 的数据,j 用来从 mapJoint 中找到对应的关节
                mapJoint[jointName[j]].channels[jointChannels[i]] = stod(keyword[(i + 6) + (k * 3)]);
            }
            ++k;
        }
    }
}
