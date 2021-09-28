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

    while (getline(file, line)) //获取每一行数据
    {
        line.erase(std::remove_if(line.begin(), line.end(), &delSubstr), line.end());
        lines.push_back(line); //将每一行依次存入到 vector 中
    }
    file.close();
    line.shrink_to_fit();

    mapKeyword["ROOT"] = 1;
    mapKeyword["JOINT"] = 2;
    mapKeyword["OFFSET"] = 3;
    mapKeyword["CHANNELS"] = 4;
    mapKeyword["End"] = 5;
    mapKeyword["{"] = 6;
    mapKeyword["}"] = 7;
    vector<string> jointName;
    vector<string>::iterator it;
    for (it = lines.begin(); it != lines.end(); ++it)
    {
        vector<string> keyword = splitString(*it, " ");
        switch (mapKeyword.find(keyword[0])->second)
        {
        case 1:
        case 2:
            jointName.push_back(setJointName(keyword));
            break;
        case 3:
            setOffsetValue(jointName, keyword);
            break;
        case 4:
            setChannels(jointName, keyword);
            break;
        case 5:
            setEndSiteValue(jointName);
            break;
        case 6:
        case 7:
            addChildrenJoint(jointName, keyword);
            break;
        default:
            break;
        }
    }
}

void BvhFile::resetData()
{
    // channels.clear();
    // joints.clear();
    motions.clear();

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
            if (rightBracket > rightBracketLevel)
            {
                if (mapJoint[jointName[leftBracket - rightBracket - 2]].hasEndSite == false)
                {
                    mapJoint[jointName[leftBracket - rightBracket - 2]].children[jointName[leftBracket - 2]] = (&(mapJoint[jointName[leftBracket - 2]]));
                }
                rightBracketLevel = rightBracket;
            }

            if (rightBracketLevel > 0)
            {
                if (mapJoint[jointName[leftBracket - 3]].hasEndSite == false)
                {
                    mapJoint[jointName[leftBracket - 3]].children[jointName[leftBracket - 2]] = (&(mapJoint[jointName[leftBracket - 2]]));
                }
            }
            else if (mapJoint[jointName[leftBracket - 2]].hasEndSite == false)
            {
                mapJoint[jointName[leftBracket - 2]].children[jointName[leftBracket - 1]] = (&(mapJoint[jointName[leftBracket - 1]]));
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
    if (isEndSite)
    {
        for (int i = 1; i < keyword.size(); ++i)
        {
            mapJoint[jointName[leftBracket - 2]].offset[i - 1] = stod(keyword[i].c_str());
        }
        isEndSite = false;
    }
    else
    {
        for (int i = 1; i < keyword.size(); ++i)
        {
            if (rightBracket > 0)
            {
                mapJoint[jointName[leftBracket - 2]].offset[i - 1] = stod(keyword[i].c_str());
            }
            else
            {
                mapJoint[jointName[leftBracket - 1]].offset[i - 1] = stod(keyword[i].c_str());
            }
        }
    }
}

// 写入 CHANNELS 数据
void BvhFile::setChannels(vector<string> jointName, vector<string> keyword)
{
    for (int i = 2; i < keyword.size(); ++i)
    {
        if (rightBracket > 0)
        {
            mapJoint[jointName[leftBracket - 2]].channels.push_back(keyword[i]);
        }
        else
        {
            mapJoint[jointName[leftBracket - 1]].channels.push_back(keyword[i]);
        }
    }
}

// 写入 End Site 值
void BvhFile::setEndSiteValue(vector<string> jointName)
{
    isEndSite = true;
    if (rightBracket > 0)
    {
        mapJoint[jointName[leftBracket - 2]].hasEndSite = true;
    }
    else
    {
        mapJoint[jointName[leftBracket - 1]].hasEndSite = true;
    }
}