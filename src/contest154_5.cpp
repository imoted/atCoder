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
 
template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}
 
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
// ------------>8------------------------------------->8------------

// typedef pair<int, int> pii;
// typedef pair<ll, int> pli;
// typedef pair<ll, ll> pll;
// typedef vector<int> veci;
// typedef vector<long long> vecl;
 
	
ll dp[102][2][5];

signed main() {
	INIT;

	
	VAR(string, s);
	VAR(int,k);

	dp[0][0][0] = 1;

	REP(i,s.size()) REP(j, 2) REP(l, k + 1) {
			int lim = j ? 9 : (s[i] - '0');
			REP(d, lim + 1) {
				dp[i + 1][j || d < lim][l + (d != 0)] += dp[i][j][l];
			}
		}

	int ans = 0;
	REP(j, 2) ans += dp[s.size()][j][k];
	OUT(ans)BR;

	return 0;
}




// // #define LOCAL
// #ifdef LOCAL
// 	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
// #else
// 	#define eprintf(...) 42
// #endif

//   int x =10;
//   int y =5;
//   swap(x,y);
//   cout << min(x,y)<< '\n';
//   cout << max(x,y)<< '\n';

//   cin >> N >> K;
//   REP(i,N){
//     cin >> X;
//     V.pb(X);
//   }


// //   foo = mp(a,b);
// //   eprintf ("a = %d, b = %d", a, b);
// //   cout << foo.fi;
// //   cout << foo.se;
  
// //   printf("%lld\n", ans);

//     string s, t;
//     cin >> s;
//     cout << s << endl;
//     s = s + t; //連結
//     s == t; //比較
//     s.length(); //長さ
//     cout << s[0] << '\n';    //i番目の文字を参照
//     cout << s.substr(0, 5)<< '\n'; //i番目以降k文字を抽出して得られる文字列
//     cout << s.find("abc")<< '\n';  //sの中に文字列tがあればその先頭のアドレスを返す．なければs.nopsを返却
//     cout << s.replace(0, 3, "zxc")<< '\n'; //i番目以降k文字を文字列tで置換する．tを空文字列にすれば削除の動作
//     cout << s.insert(5, "ins")<< '\n'; //i番目の文字の前に文字列tを挿入

//     vector<int> a{1,2,3,4,5};
//     cout << a.size()<< '\n'; //aの大きさ
//     cout << a[3]<< '\n'; //i番目の要素にアクセス
//     cout << a.front()<< '\n';  //先頭を参照
//     cout << a.back()<< '\n';   //末尾を参照
//     a.push_back(10);  //末尾に要素を追加
//     // cout << a << '\n';
//     a.pop_back();   //末尾の要素を削除
//     // cout << a << '\n';

//     FOR(i,0,10){
//         //   vec.push_back(i);
//         a.pb(i);
//     }
//     // reverse(a, a.end());
//     sort(ALL(a));
//     cout << binary_search(a.begin(), a.end(), 20)<< '\n'; //trueかfalseを返す
//     vector<int>::iterator lit = lower_bound(a.begin(), a.end(), 5);   //x以上の値が初めて現れる位置のイテレータを返す
//     vector<int>::iterator uit = upper_bound(a.begin(), a.end(), x);   //xより大きい値が初めて現れる位置のイテレータを返す 
// 	if(lit != a.end() && lit != uit)
// 		cout << uit - lit << '\n';	// この場合, ult - lit は vc 中の x の個数になる    
//     // cout << equal_range(a.begin(), a.end(), x)<< '\n';   //上記２カ所のイテレータのペアを返す