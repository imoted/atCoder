// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{
    int64_t n, q;
    std::cin >> n;
    std::vector<int64_t> a(n);
    for(int i = 0;i < n; i++){
        std::cin >> a[i];
    }
    std::sort(a.begin(),a.end());
    std::cin >> q;
    std::vector<int64_t> b(q);
    for(int64_t i =0;i < q; i++){
        std::cin >> b[i];
    }
    for(int64_t i =0; i < q;i++){
        auto it = std::lower_bound(a.begin(), a.end(), b[i]);
        std::size_t pos = std::distance(a.begin(), it);
        int64_t ans = 0;
        if(pos == 0)
            ans = std::abs(b[i] - a[pos]);
        else
            ans = std::min(std::abs(b[i]- a[pos -1] ), std::abs( b[i]- a[pos] ) );
        std::cout << ans << std::endl;
    }
}