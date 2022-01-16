// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
// #include <algorithm>

int64_t n,a,b,c,ans = 1e9;

int dfs(int am, int bm, int cm){
    if( am * a + bm * b + cm * c == n)
        return am + bm + cm;
    if( am + bm + cm >= 9999)
        return 1e9;
    return  std::min( dfs(am, bm, cm+1 ), std::min(dfs(am+1, bm, cm ), dfs(am, bm+1, cm )));
}
int main()
{
    std::cin >> n;
    


    std::cout << ans << std::endl;
    
}