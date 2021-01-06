#include <bits/stdc++.h>
using namespace std;

// input
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__); // __VA_ARGS__可変引数マクロ
template<typename T> void MACRO_VAR_Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest& ...rest) { std::cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& R:c)for(auto& w:R)std::cin>>w;
// output
template<typename T>void MACRO_OUT(const T t) { std::cout << t; }
template<typename First, typename...Rest>void MACRO_OUT(const First first, const Rest...rest) { std::cout << first << " "; MACRO_OUT(rest...); }
#define OUT(...) MACRO_OUT(__VA_ARGS__);
#define FOUT(n, dist) std::cout<<std::fixed<<std::setprecision(n)<<(dist); // std::fixed 浮動小数点の書式 / setprecision 浮動小数点数を出力する精度を設定する。
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
// utility
#define ALL(a) (a).begin(),(a).end()
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define REP(w, n) for(int w=0;w<int(n);++w)
#define IN(a, x, b) (a<=x && x<b)
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }
template<class T> using V = std::vector<T>;
template<class T> using VV = V<V<T>>;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<int, int>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = (1 << 30) - 1;                    // 1.07x10^ 9
constexpr int INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;                          // 1.15x10^18
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^18
constexpr double eps = 1e-7;
constexpr int MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;
template<class T, size_t N> void FILL(T(&a)[N], const T & val) { for (auto& x : a) x = val; }   //  int a[5] = {1,2,3,4,5};	FILL(a,10);
template<class ARY, size_t N, size_t M, class T> void FILL(ARY(&a)[N][M], const T & val) { for (auto& b : a) FILL(b, val); }  // ２次元配列でもそのまま使える
template<class T> void FILL(std::vector<T> & a, const T & val) { for (auto& x : a) x = val; }   //	使い方 vector<int> a(3);	FILL(a,10);
template<class ARY, class T> void FILL(std::vector<std::vector<ARY>> & a, const T & val) { for (auto& b : a) FILL(b, val); }  // ２次元配列でもそのまま使える
// ------------>8------------------------------------->8------------

V<int> pos_x = {1,0,-1,0};
V<int> pos_y = {0,1,0,-1};
// int h,w,ch,cw,dh,dw;
// char s[1000][1000];

// int dfs (int x,int y,int cnt){
//     int dx,dy;
//     if (x >= w || x < 0 || y >= h || y < 0 ) {
//        return -1;
//     }
//     if (s[y][x] == '#')
//     {
//         return -1;
//     }
//     if(x == dw && y == dh){
//         return cnt;
//     }
//     REP(i,4){
//         dx = pos_x[i];
//         dy = pos_y[i];            
//         // dfs(x + dx, y + dy, cnt);
//         dfs(x+dx , y+dy , cnt);
//     }

// }


int main() {
INIT;

int h,w,ch,cw,dh,dw;

cin >> h >> w >> ch >> cw >> dh >> dw;
MAT(char,s,h,w)
ch--; cw--; dh--; dw--;

int ans =0;
// queue<ll> que;
deque<PAIR> q;
V<V<int>> dist(h,V<int>(w,INFINT));

// int start = w * ch + cw;
// que.push(start);

q.emplace_back(ch,cw);
dist[ch][cw] = 0;

while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    int d = dist[y][x]; 
    q.pop_front(); 
    REP(i,4){
        int dx = pos_x[i];
        int dy = pos_y[i]; 
        int nxi = x + dx; int nyi = y + dy;
        if (nxi >= w || nxi < 0 || nyi >= h || nyi < 0 ) {
            continue;
        }
        if (s[nyi][nxi] == '#' ){
            continue; 
        }
        if (dist[nyi][nxi] <= d) {
            continue;
        }
        dist[nyi][nxi] = d;
        q.emplace_front(nyi,nxi);

    }
    for (int xi = -2; xi <= 2; xi++) {
        for (int yi = -2; yi <= 2; yi++) {
            int nxi = x + xi; int nyi = y + yi;
            if (nxi >= w || nxi < 0 || nyi >= h || nyi < 0 ) {
                continue;
            }
            if (s[nyi][nxi] == '#' ){
                continue; 
            }
            if (dist[nyi][nxi] <= d+1) {
                continue;
            }
            dist[nyi][nxi] = d+1;
            // int next = (x + dx) + w * (y + dy);
            q.emplace_back(nyi,nxi);
        }
    }
}
ans = dist[dh][dw];
if(ans == INFINT){
    OUT("-1")
}
else
{
    OUT(ans)
}

return 0;
}


