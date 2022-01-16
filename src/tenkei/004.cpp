// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int64_t h,w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> a(h,std::vector<int>(w));
    std::vector<int> w_sum(h), h_sum(w);
    for(int i =0; i < h; i++){
        for(int j = 0; j < w; j++){
            std::cin >> a[i][j];
            h_sum[j] += a[i][j];
            w_sum[i] += a[i][j];
        }
    }
    for(int i =0; i < h; i++){
        for(int j = 0; j < w; j++){
            std::cout << h_sum[j] + w_sum[i] - a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}
