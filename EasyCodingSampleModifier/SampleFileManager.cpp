#include "SampleFileManager.h"
#include <fstream>
#include <iostream>

const char* FSampleFileManager::Arg = "Arg\n";
const char* FSampleFileManager::Ans = "Ans\n";

std::string FSampleFileManager::ReadSample(std::string FilePath, int SampleNumber)
{
    std::ifstream InStream(FilePath);

    std::string Sample;
    if(InStream.is_open())
    {
        InStream.seekg(0, std::ios_base::end);
        int Size = InStream.tellg();
        InStream.seekg(0, std::ios_base::beg);

        std::unique_ptr<char[]> TempContents = std::make_unique<char[]>(Size);
        InStream.read(TempContents.get(), Size);
        std::string Samples = TempContents.get();

        size_t Pos = 0;
        for(int i = 0; i < SampleNumber - 1; ++i)
        {
            Pos = Samples.find(Arg, Pos + strlen(Arg));
        }
        size_t FromPos = Pos + strlen(Arg);

        Pos = Samples.find(Ans, Pos);
        size_t ToPos = Pos;

        Sample = Samples.substr(FromPos, ToPos - FromPos);
    }
    else
    {
        std::cout << "Can't find Sample File";
    }

    InStream.close();

    return Sample;
}
