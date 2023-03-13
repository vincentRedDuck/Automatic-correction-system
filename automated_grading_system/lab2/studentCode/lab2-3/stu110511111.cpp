//File: ex2-3.cpp

#include <iostream>
#include <iomanip>

int main()
{
    char c;
    int transtype{0};
    std::cout << "Please enter a char : ";
    std::cin >> c;  
    std::cout << "Please select an output type (1.char 2.dec 3.oct 4.hex) : ";
    std::cin >> transtype;
    if (transtype == 1)
    {
        std::cout << c;
    }
    else if (transtype == 2)
    {
        std::cout << std::dec << int(c);
    }
    else if (transtype == 3)
    {
        std::cout << std::oct << std::showbase << int(c);
    }
    else if (transtype == 4)
    {
        std::cout << std::hex << std::showbase << int(c);
    }
    else
    {
        std::cout << "No this option.";
    }
    std::cout << '\n';
   
    return 0;
}

