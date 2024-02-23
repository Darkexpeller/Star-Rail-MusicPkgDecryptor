#include"Firefly.h"
#include<string>
#include <filesystem>
#include <codecvt>
#include <time.h>
#include <new.h>

PckHeadReader::PckHeadReader(std::ifstream *File)
:pFile{File}
{
    pFile->seekg(0, std::ios::beg);
    pFile->read((char *)&Header, sizeof(Header));
    try
    {
        if(Header.Akpk!=AKPKFLAG)
            throw "Header is wrong!!!";
       
    }
    catch(char* info)
    {
        printf("%s", info);
        return;
    }
    if(Header.Akpk == AKPKFLAG)
    {
         std::cout << " Begin to handle file\n";

         FileListReader();
        }

}

void PckHeadReader::FileListReader()
{
    FireReborn::FileInfo Node;
    for (int i = 0; i < Header.FileCount;i++)
    {
        memset(&Node, 0, sizeof(Node));
        pFile->read((char *)&Node, sizeof(Node));
        FileList.push_back(Node);
    }
    pFile->seekg(4, std::ios::cur);
}

int FireReborn::Unpack(const char *FileInDir, const char *FileOutDir, int Flag)
{
    clock_t start_time = clock();

    std::filesystem::path pathObj(FileInDir);
    std::wstring fileName = pathObj.filename().wstring();
    fileName.pop_back();
    fileName.pop_back();
    fileName.pop_back();
    fileName.pop_back();
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring InDir = converter.from_bytes(FileInDir);
    std::wstring OutDir = converter.from_bytes(FileOutDir);
    if(*(OutDir.end()-1)!='/' || *(OutDir.end()-1)!='\\')
    {
        OutDir += '/';
    }
    uint8_t *buffer = NULL;
    unsigned int FileSize = 0;
    std::ifstream File(InDir, std::ifstream::binary | std::ifstream::in);
    if(File.is_open()==false)
    {

        std::cout << "Open File Failed" << std::endl;
        return 0;
    }
    PckHeadReader FileHead(&File);
//---------------------------------------------
    std::ofstream FileOut;
    std::filesystem::create_directories(std::filesystem::path((OutDir+L"OutPut/"+L"Music/")).parent_path());//检查目录
    for (int i = 0; i < FileHead.Header.FileCount;i++)
    {
        
        FileOut.open(OutDir+L"OutPut/"+L"Music/"+fileName+L"_"+std::to_wstring(i)+L".wem", std::ofstream::binary | std::ofstream::out);
        buffer = new uint8_t [FileHead.FileList[i].FileSize];
        memset(buffer, 0, FileHead.FileList[i].FileSize);
        File.read((char *)buffer,FileHead.FileList[i].FileSize);
        FileOut.write((char *)buffer, FileHead.FileList[i].FileSize);
        std::wcout << OutDir + L"OutPut/" +L"Music/" +fileName + L"_"+std::to_wstring(i) + L".wem" << L"Completed" << std::endl;
        delete []buffer;
        buffer = NULL;
        FileOut.close();
    }
    return 0;
}