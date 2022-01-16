#include <cstdlib>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    if (n % 100 == 0)
        std::cout << n / 100 << std::endl;
    else
        std::cout << n / 100 + 1 << std::endl;
}