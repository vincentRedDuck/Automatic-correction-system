//File: ex2-1.cpp
#include <iostream>

int main()
{
    int score{0};
    std::cout << "Enter your score : ";
    std::cin >> score;
    score /= 10;

    std::cout << "You got a grade : ";
    switch(score)
    {
        case 10: case 9: case 8:
            std::cout << "A\n";
            break;
        case 7:
            std::cout << "B\n";
            break;
        case 6:
            std::cout << "C\n";
            break;
        case 5:
            std::cout << "D\n";
            break;
        case 4: case 3: case 2: case 1: case 0:
            std::cout << "E\n";
            break;
    }
    return 0;
}
