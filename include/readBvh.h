#ifndef _READBVH_H
#define _READBVH_H

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace BVH
{
    // enum ChannelsEnum
    // {
    //     X_ROTATION, // X 轴旋转
    //     Y_ROTATION, // Y 轴旋转
    //     Z_ROTATION, // Z 轴旋转
    //     X_POSITION, // X 轴平移
    //     Y_POSITION, // Y 轴平移
    //     Z_POSITION, // Z 轴平移
    // };

    // struct Channel; // 前向声明
    struct Joint;

    // 关节
    struct Joint
    {
        // int index;   // 索引
        // string name; // 关节名字

        // Joint *parent = nullptr;  // 父关节
        map<string, Joint *> children; // 子关节

        double offset[3] = {0, 0, 0}; // 相对于父关节的偏移量(X,Y,Z)
        vector<string> channels;      // 该关节的位姿 CHANNEL 信息
        double site[3] = {0, 0, 0};   // 提供前关节的 OFFSET
        bool hasEndSite = false;      // 该关节是否有 End Site 这个值
    };

    // // CHANNELS 自由度
    // struct Channel
    // {
    //     int index = 0;            // 索引
    //     Joint *joint = nullptr;   // 该 CHANNEL 对应的关节
    //     ChannelsEnum typeChannel; // CHANNEL 的类型
    // };

    class BvhFile
    {
    private:
        bool loadFileState = false; // 加载文件的状态(成功/失败)
        string fileName = "";       // 文件名字

        int numJoint = 0;         // 关节的数量
        int numChannel = 0;       // 文件总 CHANNELS 数
        int numFrame = 0;         // 文件总帧数
        double frameDuartion = 0; // 每帧的持续时间
        vector<double> motions;   // 存放文件所有的运动数据块

        // vector<Joint *> joints;
        // vector<Joint *> channels;
        map<string, Joint> mapJoint; // 关节名字和关节数据对应的 map
        map<string, int> mapKeyword;

        int leftBracket = 0;
        int rightBracket = 0;
        int rightBracketLevel = 0;

    public:
        BvhFile() { resetData(); };     //创建对象时调用
        ~BvhFile() { resetData(); };    // 回收对象时调用
        void loadFile(string filePath); // 读取文件数据
        void resetData();               // 重置容器中的读取的文件数据

        string getFileName(string filePath);                                     // 获取文件名字
        bool judgeFileType(string filePath);                                     // 判断文件类型是否为 BVH
        static bool delSubstr(char c);                                           // 删除读取的字符串中的特定字符,该函数作为回调函数
        vector<string> splitString(const string &str, const string &pattern);    // 分割字符串
        string setJointName(vector<string> keyword);                             // 写入关节名字
        void addChildrenJoint(vector<string> jointName, vector<string> keyword); // 为关节添加子关节
        void setOffsetValue(vector<string> jointName, vector<string> keyword);   // 写入 OFFSET 数据
        void setChannels(vector<string> jointName, vector<string> keyword);      // 写入 CHANNELS 数据
        void setEndSiteValue(vector<string> jointName, vector<string> keyword);  // 写入 End Site 值
    };
} // namespace BVH

#endif
