#include <iostream>
#include <vector>
#include <algorithm> 

int main(){
    int64_t n;
    std::cin >> n;
    std::vector<int64_t> d(n);
    std::vector<int64_t> ans_list;
    int64_t last_value = -1;
    for(uint16_t i =0; i < n; i++){
        std::cin >> d[i];
    }
    std::sort(d.begin(),d.end());
    
    for(int i =0; i < n; i ++){
        if(d [i] != last_value )
            ans_list.push_back(d[i]);
        last_value = d[i];
    }

    std::cout << ans_list.size() << std::endl;

return 0;
}