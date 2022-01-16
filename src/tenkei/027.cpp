// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    //    std::vector<std::string> s(n);
    std::string s;
    std::map<std::string, int> s_map;
    for (int i = 0; i < n; i++)
    {
        std::cin >> s;
        if (!s_map[s])
            s_map[s] = i + 1;
        //std::cin >> s[i];
    }
    std::vector<int> ans_list;
    for (auto sval : s_map)
    {
        //if( std::find( s.begin(), s.begin() + i , s[i] ) == s.begin() +i ){
        //    std::cout << i +1 << std::endl;
        //}
        // std::cout << sval.second << std::endl;
        ans_list.push_back(sval.second);
    }
    std::sort(ans_list.begin(), ans_list.end());

    for (auto ans : ans_list)
        std::cout << ans << std::endl;

    return 0;
}

// GCC reference:
//   https://gcc.gnu.org/