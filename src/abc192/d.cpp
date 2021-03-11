#include <bits/stdc++.h>
using namespace std;

#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__); // __VA_ARGS__可変引数マクロ
template<typename T> void MACRO_VAR_Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest& ...rest) { std::cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& R:c)for(auto& w:R)std::cin>>w;
template<typename T>void MACRO_OUT(const T t) { std::cout << t; }
template<typename First, typename...Rest>void MACRO_OUT(const First first, const Rest...rest) { std::cout << first << " "; MACRO_OUT(rest...); }
#define OUT(...) MACRO_OUT(__VA_ARGS__);
#define FOUT(n, dist) std::cout<<std::fixed<<std::setprecision(n)<<(dist); // std::fixed 浮動小数点の書式 / setprecision 浮動小数点数を出力する精度を設定する。
#define SP std::cout<<" ";
#define BR std::cout<<"\n";
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
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



int main() {
INIT;

VAR(string,x)
VAR(ll,m)

V<int> s(x.size()); // stringをint配列に変換
int max_char =0;
REP(i,x.size()){
    s[i] = x[i] -'0';
    max_char = max(max_char, s[i]);
}

ll j =max_char; //+1; // n 進法

// ll sum =0;
// int is_over =0;
// while(is_over ==0){ // これだと、最大で 10の18乗回回ってしまう。
//     j++;
//     sum =0;
//     REP(i,x.size()){ // max 60
//         // __int128_t unit = pow( j , x.size() -i -1);
//         __int128_t powe =1;
//         REP(k,x.size() -i -1 ){ // max 60
//             powe *= j;
//             if(powe > m)
//                 is_over =1;
//         }
//         sum += powe * s[i];
//         if(sum > m )
//             is_over =1;
//     }
// }
// OUT(j-max_char -1)

// 2文探索する
// また Xがひと桁の場合は、mと比較して、大きければ 1 小さければ 1を出力する。

if(x.size() == 1){
    if(stoi(x) <= m) OUT(1)
    else OUT(0)
    return 0;
}

ll ac = max_char, wa = m+1; // m +1は絶対だめなので
while (wa -ac >1){
    ll n = (ac + wa) /2;  // n進数 を試す。 n進数は 正解と、間違えの中間を取る
    ll v = 0; // n進数から10進数に変換した時の数
    for(char c : x){
        if( v > m / n) v = m+1;  // v*n ( m = 10^18 : v = 10^18 )は、オーバーフローするので、nで両辺割っている。
        else v = v * n + (c - '0'); // n進数から 10進数に変換
    }
    if(v <= m) ac = n; // m以下だったら、n進数はOKなので、 AC
    else wa = n; 
}
OUT(ac-max_char)

return 0;
}


