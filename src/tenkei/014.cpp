// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{
    int64_t n;
    std::cin >> n;
    std::vector<int64_t> a(n);
    std::vector<int64_t> b(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        std::cin >> b[i];
    }
    std::sort(a.begin(),a.end());
    std::sort(b.begin(),b.end());
    int64_t ans =0;
    for(int i = 0; i < n; i++){
        ans += std::abs(a[i] - b[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}
