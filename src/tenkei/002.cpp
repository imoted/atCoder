// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main()
{
    int64_t n;
    std::cin >>n;
    std::vector<char> n_list;
    for(int i =0; i < n; i++){
        if(i < n/2)
            n_list.push_back('(');
        else
            n_list.push_back(')');
    }
    // std::cout << n_str;
    if(n %2 == 1){
        return 0;
    }
    else{
        do{
            bool is_no = false;
            std::vector<char> stack;
            for(auto c: n_list){
                if(c == '(')
                    stack.push_back(c);
                else{
                    if(stack.size()){
                        stack.pop_back();
                    }
                    else{
                        is_no = true;
                        break;
                    }
                }
            }
            if(!is_no){
                for(int i =0; i < n_list.size(); i++)
                    std::cout << n_list[i];
                std::cout << std::endl;
            }
        }while(std::next_permutation(n_list.begin(),n_list.end()));
   }
}

// GCC reference:
//   https://gcc.gnu.org/

// C++ language references:
//   https://cppreference.com/
//   https://isocpp.org/
//   http://www.open-std.org/jtc1/sc22/wg21/

// Boost libraries references:
//   https://www.boost.org/doc/
