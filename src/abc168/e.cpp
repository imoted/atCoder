#include <bits/stdc++.h>
using namespace std;

// input
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__); // __VA_ARGS__可変引数マクロ
template<typename T> void MACRO_VAR_Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest& ...rest) { std::cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC_ROW(type, n, ...)std::vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int w_=0; w_<n; ++w_){MACRO_VEC_ROW_Scan(w_, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest& ...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { std::cin >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest& ...rest) { std::cin >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& R:c)for(auto& w:R)std::cin>>w;
// output
template<typename T>void MACRO_OUT(const T t) { std::cout << t; }
template<typename First, typename...Rest>void MACRO_OUT(const First first, const Rest...rest) { std::cout << first << " "; MACRO_OUT(rest...); }
#define OUT(...) MACRO_OUT(__VA_ARGS__);
#define FOUT(n, dist) std::cout<<std::fixed<<std::setprecision(n)<<(dist); // std::fixed 浮動小数点の書式 / setprecision 浮動小数点数を出力する精度を設定する。
#define SOUT(n, c, dist) std::cout<<std::setw(n)<<std::setfill(c)<<(dist);
#define EOUT(...) { OUT(__VA_ARGS__)BR; exit(0); }
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define SHOW(dist) {std::cerr << #dist << "\t: " << (dist) << "\n";}
#define SHOWVECTOR(v) {std::cerr << #v << "\t: ";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t: ";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}
#define SHOWSTACK(a) {auto tmp(a);std::cerr << #a << "\t: ";while(!tmp.empty()){std::cerr << tmp.top() << " ";tmp.pop();}std::cerr << "\n";}

#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
// utility
#define ALL(a) (a).begin(),(a).end()
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define RFOR(w, a, n) for(int w=(n)-1;w>=(a);--w)
#define REP(w, n) for(int w=0;w<int(n);++w)
#define RREP(w, n) for(int w=int(n)-1;w>=0;--w)
#define IN(a, x, b) (a<=x && x<b)
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }

#define PB push_back // 配列の最後にappendする
#define MP make_pair 
#define FI first
#define SE second

// test
template<class T> using V = std::vector<T>;
template<class T> using VV = V<V<T>>;
 
// template<typename S, typename T>
// std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
// 	os << "(" << p.first << ", " << p.second << ")"; return os;
// }
 
// type/const
// #define int ll
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
template<class T, size_t N> void FILL(T(&a)[N], const T & val) { for (auto& x : a) x = val; }
template<class ARY, size_t N, size_t M, class T> void FILL(ARY(&a)[N][M], const T & val) { for (auto& b : a) FILL(b, val); }
template<class T> void FILL(std::vector<T> & a, const T & val) { for (auto& x : a) x = val; }
template<class ARY, class T> void FILL(std::vector<std::vector<ARY>> & a, const T & val) { for (auto& b : a) FILL(b, val); }
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
	explicit operator int() const { return x; }						   // added by QCFium
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

mint combination(ull s, ull r) {
  if ( r * 2 > s ) r = s - r;
  mint dividend = 1;
  mint divisor  = 1;
  for ( ull i = 1; i <= r; ++i ) {
    dividend *= (s-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}


int main() {
	INIT;

// n 3

// a b
// 1 2
// -1 1
// 2 -1

// 以下ではダメ。　式変形が大事。
// a[i] * a[j] + b[i] * b[j] != 0
// 上記を計算し、抽出する。　全通りから、上記を減算して、出力
// 上記条件を探る

// a[i] * a[j] + b[i] * b[j] != 0
// 最小公約数を先に計算　
// gcd(a, b)
// それでa , bを割る
// その後、

// VEC(ll,v,n);
// MAT(ll,c,n,m);

VAR(int,n);
V<ll> a(n);
V<ll> b(n);
V<ll> d(n);
int c;
int zero =0;

REP(i,n){
	cin >> a[i] >> b[i];
	if(a[i] == && b[i] ==0){
		zero++;
		continue;
	}
	c = gcd(a[i], b[i]);
	if(c != 0){
		a[i] /= c;
		b[i] /= c;
	}
	if(b[i] !=0)
		c[i] = a[i] / b[i];
	// d[i] = a[i] * b[i];
}

// sort(d.begin(),d.end());
// ll cnt =0;

REP(i,n){

	// if(d[i] == d[i+1]){
	// 	if((a[i] == b[i+1] && a[i+1] == - b[i]) || (a[i] == - b[i+1] && a[i+1] == b[i]))
	// 		cnt++;
	// }
}

OUT(pow(2,n) -1 - cnt)

return 0;
}

// 10  1024 -4 -> 1019xxxx -> 479
// 3 2                   6
// 3 2                   6
// -1 1                  -1
// 2 -1                  -2
// -3 -9   -1 -3         3
// -8 12   -2 3          -6
// 7 7   1  1            1
// 8 1                   8
// 8 2   4 1             4
// 8 4   2 1             2
