#include "SettingFileManager.h"
#include "SampleFileManager.h"
#include <iostream>

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cout << "More Arguments Required" << std::endl;
        std::cout << "{ Setting File Path } { Sample File Path } { Sample Number }";
        return 1;
    }

    std::string SettingFilePath = argv[1];
    FSettingFileManager SettingFileManager(SettingFilePath);

    FSampleFileManager SampleFileManager;

    std::string SampleFilePath = argv[2];
    int SampleNumber = std::stoi(std::string(argv[3]));
    std::string Content = SampleFileManager.ReadSample(SampleFilePath, SampleNumber);

    SettingFileManager.Write(Content);

    return 0;
}