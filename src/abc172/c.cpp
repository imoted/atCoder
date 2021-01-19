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

// test
template<class T> using V = std::vector<T>;
template<class T> using VV = V<V<T>>;
 
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

// k < 10^9
// dp[x][y] x/y  n/mのindex 読んだ本の数
// 

int main() {
	INIT;

VAR(ll,n,m,k)
V<ll> a(n);
V<ll> b(m);
V<ll> sum_a(n);
V<ll> sum_b(m);

ll val =0;;
REP(i,n){
	cin >> a[i];
	val += a[i];
	sum_a[i] = val ;
}
val =0;
REP(i,m){
	cin >> b[i];
	val += b[i];
	sum_b[i] += val;
}

// しゃくとり法  O(N+M)   
ll sum=0;
int ans =0;
REP(i,m) // bを全部読んだと仮定
	sum += b[i];
int j =m;
REP(i,n+1){ // aを順番に回す   0 -> n　　で冊数を増やしていく   O(N)
	while (j > 0 && sum>k){   // bをm -> 0で減らす。　k以上の時間がかかる and bの冊数が０以上である    O(M)にならず、Mの個数が減っていく
		j--;
		sum -= b[j];
	}
	if (sum > k) break;   // もしいくらbの冊数を減らしても、時間がkより小さくならないなら、終わり
	ans = max(ans, i+j);  //読んだ冊数は、 i(a)とj (b)を足したもの
	if (i == n) break;   // aを読んだ数が、nなら終わり  配列外参照を防ぐ為
	sum += a[i];    // 時間合計に　次読んだ aの本を足す
}
OUT(ans)


// 2分探索   O(N logM)
// ll sum = 0;
// ll ans = distance(sum_a.begin(), upper_bound(sum_a.begin(), sum_a.end(), k) ) ;
// REP(i,n){ // aから何冊読むのかをループ  0 -> n冊まで
// 	// sum += a[i];
// 	if(k > sum_a[i]){  //  時間以内で、aがi冊読めるなら
// 		V<ll>::iterator it =upper_bound(sum_b.begin(), sum_b.end(), k - sum_a[i]);  
// 		ll pos = distance(sum_b.begin(), it);
// 		ans = max(ans, pos + i +1);
// 	}
// }

// OUT(ans)


return 0;
}