#include <iostream>
#include <string>

int Solve()
{
    int IntInputCount;
    std::cin >> IntInputCount;

    int TotalInput = 0;
    for(int i = 0; i < IntInputCount; ++i)
    {
        int TempInput;
        std::cin >> TempInput;
        TotalInput += TempInput;
    }
    std::cout << TotalInput;

    std::cout << std::endl;

    int StrInputCount;
    std::cin >> StrInputCount;

    std::string TotalStr;
    for(int i = 0; i < StrInputCount; ++i)
    {
        std::string TempInput;
        std::cin >> TempInput;
        TotalStr += TempInput + " ";
    }
    std::cout << TotalStr;

    return 0;
}