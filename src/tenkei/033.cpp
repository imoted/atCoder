// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <cmath>
//#include <numeric>

int main()
{
    int h, w;
    std::cin >> h >> w;
    int ans = 0;
    for (int bit = 0; bit < (1 << h * w); bit++)
    {
        // for (int bit_w = 0; bit_w < (1 << w); bit_w++)
        int cnt = 0;
        for (int i_h = 0; i_h < h - 1; i_h++)
        {
            for (int i_w = 0; i_w < w - 1; i_w++)
            {
                // if (bit_h >> i_h & 1 + bit_w >> i_w & 1 + bit_h >> (i_h + 1) & 1 + bit_w >> (i_w + 1) & 1 <= 1)
                // cnt++;
            }
        }
        ans = std::max(ans, cnt);
        // }
    }
    std::cout << ans << std::endl;
    return 0;
}