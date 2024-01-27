#include "SettingFileManager.h"
#include <fstream>
#include <sstream>

const char *FSettingFileManager::EmptySettingFile = "{\n"
                                                    "   \"cmake.debugConfig\": {\n"
                                                    "        \"args\" : [\n"
                                                    "        ]\n"
                                                    "    },\n"
                                                    "}";
const char* FSettingFileManager::CMakeDebugConfig = "\"cmake.debugConfig\"";
const char* FSettingFileManager::Args = "\"args\" : [\n";
const char* FSettingFileManager::End = "]\n";

FSettingFileManager::FSettingFileManager(std::string SettingFilePath) : Path(SettingFilePath)
{
    std::ifstream InStream(SettingFilePath);

    std::unique_ptr<char[]> Contents;
    if(InStream.is_open())
    {
        InStream.seekg(0, std::ios_base::end);
        int Size = InStream.tellg();
        InStream.seekg(0, std::ios_base::beg);

        Contents = std::make_unique<char[]>(Size);
        InStream.read(Contents.get(), Size);
    }
    else
    {
        int Size = strlen(EmptySettingFile) + 1;
        Contents = std::make_unique<char[]>(Size);
        strcpy_s(Contents.get(), Size, EmptySettingFile);
    }
    SettingData = Contents.get();

    InStream.close();
}

void FSettingFileManager::Write(std::string Contents)
{
    std::ofstream OutStream(Path);

    size_t Pos = SettingData.find(CMakeDebugConfig);
    Pos = SettingData.find(Args, Pos) + strlen(Args);
    OutStream.write(SettingData.c_str(), Pos);

    for(int i = 0; i < TabCount + 1; ++i)
    {
        OutStream.write(Tab, strlen(Tab));
    }

    std::istringstream StringStream(Contents);
    while(!StringStream.eof())
    {
        std::string Param;
        StringStream >> Param;
        if(!Param.empty())
        {
            OutStream.write("\"", 1);

            OutStream.write(Param.c_str(), Param.size());

            OutStream.write("\", ", 3);
        }
    }
    OutStream.write("\n", 1);

    for(int i = 0; i < TabCount; ++i)
    {
        OutStream.write(Tab, strlen(Tab));
    }
    Pos = SettingData.find(End, Pos);
    OutStream.write(SettingData.c_str() + Pos, SettingData.size() - Pos);

    OutStream.close();
}
