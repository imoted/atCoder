// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += std::abs(a[i] - b[i]);
    }
    if ((k - ans) % 2 == 0 && (k - ans) >= 0)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}
