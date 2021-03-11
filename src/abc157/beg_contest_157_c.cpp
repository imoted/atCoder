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
 
// type/const
#define int ll
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


signed main() {
	INIT;

VAR(ll,n,m);
V<PAIR> s(m);

REP(i,m)
	cin >> s[i].first >> s[i].second;

REP(x,1000){
	int keta =1;
	int nx = x/10;
	V<int> d(1,x%10);
	while(nx){
		keta++;
		d.push_back(nx%10);
		nx /=10;
	}
	if (keta !=n) {
		continue;
	}
	bool ok = true;
	reverse(ALL(d));
	REP(i,n){
		if (d[s[i].first-1] != s[i].second) ok = false; 
	}
	if(ok){
		OUT(x)
		return 0;
	}
}
OUT(-1);
return 0;


// 以下WA

// MAT(ll,sc_list ,m,2);

// 数値型への変換
// string s = "1";
// ll a=0;
// ll tmp =9;
// vector<ll> min_int(n);
// string min_string ;
// bool f_found =0;

// REP(j,n){ // 
// 	min_int[j] =0;
// 	f_found =0;
// 	REP(i,m){ // 
// 		if(sc_list[i][0] == j +1){
// 			CHMIN(tmp,sc_list[i][1]);
// 			f_found =1;
// 		}
	
// 	}
// 	if(f_found ==0){tmp =0;}
// 	min_int[j] = tmp;
// 	tmp =9;
// }

// REP(j,n){
// 	min_string += to_string(min_int[j]);
// }

// ll ans;
// // if (min_string.length() != n ){
// // 	OUT(-1)
// // 	return 0;
// // }

// ans = stoi(min_string);

// if ( n==1){
// 	if (ans < 10 ){
// 		OUT(ans);
// 		return 0;
// 	}
// }
// if ( n==2){
// 	if (ans >= 10 && ans <100 ){
// 		OUT(ans);
// 		return 0;
// 	}
// }
// if ( n==3){
// 	if (ans >= 100 && ans <1000 ){
// 		OUT(ans);
// 		return 0;
// 	}
// }
// OUT(-1);

// 数値　→　文字列への変換
// auto s = std::to_string(i);


//  return 0;
}
