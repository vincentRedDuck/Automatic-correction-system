#include <iostream>
#include <cmath>

int main ()
{
    std::cout << "Enter first point:";
    char a = '0';
    int x1 = '0';
    char b = '0';
    int y1 = '0';
    char c = '0';
    std::cin >> a >> x1 >> b >> y1 >> c;
    std::cout << "Enter second point:";
    int x2 = '0';
    int y2 = '0';
    std::cin >> a >> x2 >> b >> y2 >> c;
    while (x1!=x2 || y1!=y2)
    {
        std::cout << "Distance: " << sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) << '\n';
        std::cout << "Enter first point:";
        std::cin >> a >> x1 >> b >> y1 >> c;
        std::cout << "Enter second point:";
        std::cin >> a >> x2 >> b >> y2 >> c;
    }
    
    return 0;
}
