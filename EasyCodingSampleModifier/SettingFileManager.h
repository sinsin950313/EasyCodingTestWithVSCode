#pragma once

#include <string>

class FSettingFileManager
{
private:
    static const char* EmptySettingFile;
    static const char* CMakeDebugConfig;
    static const char* Args;
    static const char* End;

public:
    FSettingFileManager(std::string SettingFilePath);

    void Write(std::string Contents);

private:
    std::string Path;

    std::string SettingData;

    int TabCount = 2;

    char* Tab = "    ";
};