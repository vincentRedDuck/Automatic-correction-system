//File: ex2-2
#include <iostream>
#include <iomanip>

int main()
{
    double num{0};
    std::cout << "Enter a num : ";
    std::cin >> num;

    std::cout << '\n' << "123456789~123456789~123456789~123456789~123456789~123456789~123456789~123456789~\n";
    std::cout << "number                        scientific              signed          precision4\n";
    std::cout << std::setw(20) << std::left << std::fixed << std::setprecision(6) << num;
    std::cout << std::setw(20) << std::uppercase << std::right << std::scientific << num;
    std::cout.unsetf(std::ios::scientific);
    std::cout << std::setw(20) << std::showpos << std::right << std::fixed << std::setprecision(6) << num;
    std::cout.unsetf(std::ios::showpos);
    std::cout << std::setw(20) << std::right << std::fixed << std::setprecision(4) << num;
    std::cout << '\n';
    return 0;
}
