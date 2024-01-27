#pragma once

#include <string>

class FSampleFileManager
{
private:
    static const char* Arg;

    static const char* Ans;

public:
    std::string ReadSample(std::string FilePath, int SampleNumber);
};