#include <iostream>
#include <limits>

void DecimalToUnary(int x)
{
    for(int i=0; i<x; i++)
    {
        std::cout << "1";
    }
    std::cout << "\n";
}

int main()
{
    int szam;
    
    std::cout << "Adj meg egy szamot:\n";
    
    std::cin >> szam;
    
    DecimalToUnary(szam);
    
    return 0;
    
    
}