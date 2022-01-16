#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

// 計算量
// N = 800 k =2 だと、799 * 799 × sort -> O(k^2 log k^2)
// 6 * 10^5 * 4 

// N = 800 k = 100   :  700* 700 * O(k^2)
// 5 * 1e5 * 1e4 * log(xxx)
// 破綻?

// N = 800 k = 300   :  500* 500 * O(k^2)
// 3 * 1e5 * 9 e4 * log(xxx)
// 破綻

// sortをしたくない。
// そうすれば、N = 800 k = 100でも 5e5ぐらい。

// mapをするのも無理。　k =100でヒスト作るのでも無理。
// そもそも kで作られた中身を１個づつ処理ができない

// 2分探索でやるのが正解
// 答えはX以下ですか？　に置き換える。
// Xが５　だと
// 0 1 0
// 0 1 1
// 1 0 0
// となる。
// 中央値が０ならOK

// 大きい方から、L番目の値が０
// →　１がL個未満
// →　値がL未満

// ２次元累積和


int main() {
INIT;

    VAR(int,n,k)
    MAT(ll,a,n,n)

    int L = k * k / 2 + 1;

    int wa = -1;
    int ac = INFINT;
    while(wa+1 < ac){
        int wj = (wa + ac) / 2;
        bool ok = false;
        vector<vector<int>> s(n + 1, vector<int>(n + 1));
        REP(i, n) REP(j, n) s[i + 1][j + 1] = a[i][j] > wj ? 1 : 0;
        REP(i, n + 1) REP(j, n) s[i][j + 1] += s[i][j];
        REP(i, n) REP(j, n+1) s[i+1][j] += s[i][j];
        REP(i,n-k+1)REP(j,n-k+1)
        {
            int now = s[i + k][j + k];
            now -= s[i][j + k];
            now -= s[i + k][j];
            now += s[i][j];
            if(now < L)
                ok = true;
        }
        if (ok)
            ac = wj;
        else
            wa = wj;
    }
    OUT(ac)

    return 0;
}
