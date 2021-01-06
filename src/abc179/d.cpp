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

template<int mod>
struct ModInt{
 int x;
 ModInt():x(0){}
 ModInt(long long y):x(y>=0?y%mod:(mod-(-y)%mod)%mod){}
 ModInt &operator+=(const ModInt &p){
     if((x+=p.x)>=mod)x-=mod;
     return *this;
 }
 ModInt &operator-=(const ModInt &p){
     if((x+=mod-p.x)>=mod)x-=mod;
     return *this;
 }
 ModInt &operator*=(const ModInt &p){
     x=(int)(1LL*x*p.x%mod);
     return *this;
 }
 ModInt &operator/=(const ModInt &p){
     *this*=p.inverse();
     return *this;
 }
 ModInt &operator^=(long long p){
     ModInt res = 1;
     for (; p; p >>= 1) {
         if (p & 1) res *= *this;
         *this *= *this;
     }
     return *this = res;
 }
 ModInt operator-()const{return ModInt(-x);}
 ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}
 ModInt operator-(const ModInt &p)const{return ModInt(*this)-=p;}
 ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}
 ModInt operator/(const ModInt &p)const{return ModInt(*this)/=p;}
 ModInt operator^(long long p)const{return ModInt(*this)^=p;}
 bool operator==(const ModInt &p)const{return x==p.x;}
 bool operator!=(const ModInt &p)const{return x!=p.x;}
 explicit operator int() const { return x; }                        // added by QCFium
 ModInt operator=(const int p) {x = p; return ModInt(*this);} // added by QCFium
 ModInt inverse()const{
     int a=x,b=mod,u=1,v=0,t;
     while(b>0){
         t=a/b;
         a-=t*b;
         std::swap(a,b);
         u-=t*v;
         std::swap(u,v);
     }
     return ModInt(u);
 }
 friend std::ostream &operator<<(std::ostream &os,const ModInt<mod> &p){
     return os<<p.x;
 }
 friend std::istream &operator>>(std::istream &is,ModInt<mod> &a){
     long long x;
     is>>x;
     a=ModInt<mod>(x);
     return (is);
 }
};
typedef ModInt<MOD> mint;

int main() {
INIT;

VAR(int,n,k)
V<int> l(k),r(k);
REP(i,k){
    cin >> l[i] >> r[i];
}
V<mint> dp(n+1);
V<mint> dpsum(n+1);
dp[1] =1;
dpsum[1] =1;
for (int i = 2; i <= n; i++)
{
    REP(j,k){
        int ri = i - l[j];
        int li = i - r[j];
        if(ri <0 )continue;
        li = max(li,1);
        dp[i] += dpsum[ri] - dpsum[li -1];
    } 
    dpsum[i] += dpsum[i-1] + dp[i];
}
OUT(dp[n])


return 0;
}


