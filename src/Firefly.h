#ifndef FIREFLY_H
#define FIREFLY_H
#include <iostream>
#include <fstream>
#include <vector>
#define AKPKFLAG 0x4B504B41
#define VITALFLAG  0X0000007800660073

namespace FireReborn
{
    int Unpack(const char *FileInDir, const char *FileOutDir, int Flag);
    //OutPut DIR==  FileOutDir/OutPut/Music/
    struct BaseInfo
    {
        uint32_t Akpk;              //0x4B504B41
        uint32_t DataOffset;
        uint32_t UnknownHead[8];
        uint64_t VitalFlag;          //0X0000007800660073
        uint32_t UnknownZero;        //0x00000000
        uint32_t FileCount;
    };
    struct FileInfo
    {
        uint32_t UnknownOne;
        uint32_t UnkonwnTwo;
        uint32_t FileSize;
        uint32_t ContentOffset;
        uint32_t UnknownFive;
    };
}

class PckHeadReader
{
public:
    PckHeadReader(std::ifstream *File);
    void FileListReader();
    std::ifstream *pFile;
    int ContentSize = 0;
    FireReborn::BaseInfo Header;
    std::vector<FireReborn::FileInfo> FileList;
};

#endif