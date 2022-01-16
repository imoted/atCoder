#include <iostream>

int main(){
    int64_t n ,y;
    std::cin >> n >> y;
    bool is_ok = false;
    for(int cnt_1000 =0; cnt_1000 <= n; cnt_1000 ++){
        for(int cnt_5000 = 0; cnt_5000 <= n - cnt_1000; cnt_5000++){
            int64_t z = (n - cnt_1000 - cnt_5000) ;
            if( cnt_1000 * 1000 + cnt_5000 * 5000 + 10000 * z == y){
                std::cout << z << " " << cnt_5000 << " " << cnt_1000 << std::endl;
                is_ok = true;
                return 0;
            }
        }
    }
    if(!is_ok)
       std::cout << -1 << " " << -1 << " " << -1 << std::endl;
        
   return 0;
}