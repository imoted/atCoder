// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int64_t n =0, q, cv, pv;
    std::cin >> n;
    std::vector<int64_t> p_sum_1;
    std::vector<int64_t> p_sum_2;
    int64_t sum_p = 0, tmp_sum_1 =0 , tmp_sum_2 =0;
    for(int i =0; i < n; i++){
        std::cin >> cv;
        std::cin >> pv;
        if(cv == 1 ){
            tmp_sum_1 += pv;
        }
        else{
            tmp_sum_2 += pv;
        }
        p_sum_1.push_back(tmp_sum_1);
        p_sum_2.push_back(tmp_sum_2);
    }
    std::cin >> q;
    std::vector<int64_t> l(q);
    std::vector<int64_t> r(q);
    for(int i =0; i < q; i++){
        std::cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }
    for(int i =0; i < q; i++){
        if(l[i] ==0 ){
            std::cout << p_sum_1[r[i]] << " ";
        }
        else{
            std::cout << p_sum_1[ r[i]] - p_sum_1[l[i] -1] << " ";
        }
        if(l[i] ==0 ){
            std::cout << p_sum_2[r[i]] << " ";
        }
        else{
            std::cout << p_sum_2[ r[i]] - p_sum_2[l[i] -1] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}