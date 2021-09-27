#include <fstream>
#include <iostream>
#include <algorithm>
#include "readBvh.h"
using namespace BVH;

void BvhFile::loadFile(string filePath)
{
    string line;
    vector<string> lines;
    string keyword;
    Joint *parentJoint = new Joint;
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

    vector<string>::iterator it;
    mapKeyword["ROOT"] = 1;
    mapKeyword["Joint"] = 2;
    mapKeyword["CHANNELS"] = 3;
    mapKeyword["OFFSET"] = 4;
    mapKeyword["End"] = 5;
    mapKeyword["{"] = 6;
    mapKeyword["}"] = 7;
    for (it = lines.begin(); it != lines.end(); ++it)
    {
        keyword = getKeyword(it);
        switch (mapKeyword.find(keyword)->second)
        {
        case 1:
        case 2:
            setJointName(parentJoint, it);
            break;
        case 3:
            setChannels(parentJoint, it);
            break;
        case 4:
            setOffsetValue(parentJoint, it);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            ++numJoint;
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

// 获取关键字
string BvhFile::getKeyword(vector<string>::iterator it)
{
    int index = it->find(" ");
    return it->substr(0, index);
}

// 写入关节名字
void BvhFile::setJointName(Joint *parentJoint, vector<string>::iterator it)
{
    string jointName = it->substr(it->find(" ") + 1); // 获取关节名字
    mapJoint[jointName] = *parentJoint;
}

// 写入 OFFSET 数据
void BvhFile::setOffsetValue(Joint *parentJoint, vector<string>::iterator it)
{
    string offset[3];
    for (int i = 0; i < 3; ++i)
    {
        // TODO
        static int lastPos;
        lastPos = it->find(" ", lastPos) + 1;
        static int nowPos;
        nowPos = it->find(" ", lastPos);
        static int dataInterval = nowPos - lastPos;
        offset[i] = it->substr(lastPos, dataInterval);
    }

    // offset[0] = it->substr(0, it->find_first_of(" "));
    // parentJoint->offset[0] = atof(offset.c_str());
}

// 写入 CHANNELS 数据
void BvhFile::setChannels(Joint *parentJoint, vector<string>::iterator it)
{

}
