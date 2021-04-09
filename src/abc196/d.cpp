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

int h,w;
int used[16][16]; // globalのときは０で初期化される。

ll dfs(int i, int j,int a,int b){  // jが横軸 iが縦軸
    if(a <0 || b <0) 
        return 0;                   //畳の枚数が規定の枚数を超えてしまったら  成り立っていないということなので、カウントしない
    if(j == w){ 
        j=0; ++i;}           // 横にスライドしていって、横のwの範囲を超えたら、次の行
    if(i == h) 
        return 1;           // 最後の行まで置けたということは、OKなのでカウント
    if(used[i][j]) return dfs(i, j+1,a,b);  // 既に２畳のマスが置かれている場合は、次のマスにすすめる
    ll res =0;
    used[i][j] = true;             // 半畳、２畳のマスなどをどれを使っても、今のマスはしようする
    res += dfs(i, j+1,a, b-1);    //半畳を使う場合  
    if( j+1 < w && !used[i][j +1]) { //横に２畳のマスを使う  隣のますが範囲内でかつ、usedでないなら
        used[i][j+1] = true;        //横に２畳のマスを使うので、隣のマスもused
        res += dfs(i,j+1,a-1,b);   
        used[i][j+1] = false;      // dfsから帰ってきたら、今おいたのを戻してやる
    }
    if( i+1 < h && !used[i+1][j]) {
        used[i+1][j] = true;
        res += dfs(i ,j +1,a-1,b);   //縦に２畳のマスを使う
        used[i+1][j] = false;
    }
    used[i][j] = false;             // 半畳、２畳のマスなどをおいたあと、最後に戻す
    return res;
}

int main() {
INIT;

cin >> h >>w;
int a,b;
cin >> a >>b;

OUT(dfs(0,0,a,b))


return 0;
}


