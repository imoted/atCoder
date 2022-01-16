// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <vector>

const long double PI = 3.141592653589793238462643;

int main()
{
    long double t ,l ,x, y;
    int64_t q;
    std::cin >> t >> l >> x >>y >> q;
    std::vector<long double> e(q);
    for(int i =0;i <q; i++){
        std::cin >> e[i];
    }
    for(int i =0;i <q; i++){
        long double angle =  e[i] /t * 2 * PI ;
        // continue;
        long double k_z = - l / 2 * std::cos( angle) + l /2;
        long double k_x = - l / 2 * std::sin( angle) ;
        std::cout << std::setprecision(10) << std::atan( k_z  / std::sqrt( std::pow( x - k_x ,2) + std::pow( y ,2) ) ) /  (2 *  PI) * 360 << std::endl;
    }
    return 0;
}