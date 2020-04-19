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

// typedef pair<int, int> pii;
// typedef pair<ll, int> pli;
// typedef pair<ll, ll> pll;
// typedef vector<int> veci;
// typedef vector<long long> vecl;
 
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


signed main() {
	INIT;

VAR(string,s);
// VEC(ll,v,n);
// MAT(ll,c,n,m);

if(s[2] == s[3] && s[4] == s[5])cYes;
else cNo;



 return 0;
}

//////////////////////////  数値、Vectorなど配列に適用 ///////////////////////////

//     vector<int> a{1,2,3,4,5};
//     cout << a.size()<< '\n'; //aの大きさ
//     cout << a[3]<< '\n'; //i番目の要素にアクセス
//     cout << a.front()<< '\n';  //先頭を参照
//     cout << a.back()<< '\n';   //末尾を参照
//     a.push_back(10);  //末尾に要素を追加
//     a.pop_back();   //末尾の要素を削除

//"a" を b回繰り返すstringで初期化
// std::string s(b, "a");  

// 3項演算子
// (n == m ? cYES : cNO)

// 配列の重複削除に使うset 配列  insertとかで配列を作り変える？
//  std::set<int> st{3, 1, 4, 1};
//  set は重複を許さない順序付集合なので、上記のように重複データがある場合は、重複データは自動的に削除され、{1, 3, 4} だけが格納される。

// CHMAX(a,b)  a,bを比較して、でかい方をaに代入する

// 数値型への変換
//   string s = "1";
//  int a = s[0]-'0';

// ２つの変数をスワップ
// int a = 1;
// int b = 2;
// swap(a, b); // a = 2, b = 1 // 戻り値は特になし

// 配列から配列を検索
// vector<ll> v = { 1, 2, 3, 4, 5 };
// vector<ll> w = { 3,4 };
// cout << *search(v.begin(), v.end(), w.begin(), w.end()); // v.begin() + 2

//  配列から 要素を検索
// vector<int> v = { 1, 2, 3, 4, 5 };
// vector<int>::iterator itr_b = find(v.begin(), v.end(), 3); // v.begin() + 2
// cout << *itr_b;
// vector<int>::iterator itr_e = find(v.begin(), v.end(), 7); // v.end()
// cout << *itr_e;

// 同等かどうか、を判定 boolを返す
// vector<ll> v = { 1, 2, 3 };a
// vector<ll> w = { 1, 2, 3 };
// cout <<  equal(v.begin(), v.end(), w.begin()); // true
// w[0] = 2;
// cout << equal(v.begin(), v.end(), w.begin()); // false

// 配列の中から数を数える  //遅い O(N)
// vector<ll> v = { 1, 2, 1, 3, 2 };
// cout << count(v.begin(), v.end(), 1); // 2

// 配列で、配列内のそれぞれの要素のヒストグラムをmap　連想配列で作る
// REP(x,n) cnt[a[x]]++; 

// 配列の要素を入れ替える
// V<ll> v = { 1, 2, 3, 2, 1 };
// replace(v.begin(), v.end(), 2, 4); // v = { 1, 4, 3, 4, 1 }

// 配列から要素を消す  removeだけでは、ゴミがついてくるので、eraseを行う。
// V<ll> v = { 1, 2, 3, 2, 1 };
// V<ll> w = { 1, 2, 3, 2, 1 };
// remove(v.begin(), v.end(), 2);                   // v = { 1, 3, 1, ? , ? }
// remove(w.begin(), w.end(), 2), w.end(); // w = { 1,3,1}
// w.erase(remove(w.begin(), w.end(), 2), w.end()); // w = { 1,3,1}

// 連続した同じ値を消す。removeと同様新しい末尾位置を示すイテレータが返ってくる。
// 重複を無視して数え上げるときに、多くの場合setを使うよりもvectorにpush_backしていき、sortしてuniqueしたほうが速い(g++で確認)。
// V<ll> v = { 1, 1, 2, 2, 3, 3 };
// v.erase(unique(v.begin(), v.end()), v.end()); // v = { 1, 2, 3 }

// めちゃ遅い　要注意
// 逆順に並べ替える。
// 単純に逆にしたい時はもちろん、シーケンスを逆にたどるときにreverseをしておくとインデキシングが楽になるのでたまに使う。
// V<ll> v = { 1, 2, 3, 4, 5 };
// reverse(v.begin(), v.end()); // v = { 5, 4, 3, 2, 1 }

// シーケンスをシフトする。引数がなかなか難しいが、第2引数は操作後に新しく先頭になっている要素のイテレータ。
// V<ll> v = { 1, 2, 3, 4, 5 };
// rotate(v.begin(), v.begin() + 2, v.end()); // v = { 3, 4, 5, 1,2 }

// ランダムにシャッフルする。
// 乱択したい時や、特定の順番の入力に対して弱いアルゴリズムを使う時に入力をシャッフルしておくなどの使い方がある。
// V<ll> v = { 1, 2, 3, 4, 5 };
// random_shuffle(v.begin(), v.end()); // v = { 3, 5, 2, 4, 1 } (例えばこうなる)

// sort / 逆順ソートも
// V<ll> v = { 3, 5, 2, 4, 1 };
// V<ll> w = { 3, 5, 2, 4, 1 };
// sort(v.begin(), v.end());   // v = { 1, 2, 3, 4, 5 }
// sort(w.rbegin(), w.rend()); // w = { 5, 4, 3, 2, 1 } (greaterを使うより楽！)

// ソート済みのシーケンスに対して、ある値を入れるときに、最も早い/遅い位置の直後のイテレータを返す。
// 勝手に二分探索してくれるので便利。
// V<ll> v = { 1, 2, 2, 3, 3 };
// cout << *lower_bound(v.begin(), v.end(), 2); // v.begin() + 1
// cout << *upper_bound(v.begin(), v.end(), 2); // v.begin() + 3

// ソート済みのシーケンスに対して、ある値が存在するかを調べる。
// 他の操作が必要ない場合はsetを使うことで簡単にかけるので使う頻度は少ないかもしれない。
// V<ll> v = { 1, 2, 2, 3, 3 };
// cout << binary_search(v.begin(), v.end(), 2); // true
// cout << binary_search(v.begin(), v.end(), 4); // false

// シーケンス中の最大値/最小値「のイテレータ」を返す。
// 単純に最大値/最小値が欲しい時のほか、そのインデックスまで分かるため、非常に便利。
// V<ll> v = { 3, 5, 2, 4, 1 };
// cout << *max_element(v.begin(), v.end()); // 5
// cout << max_element(v.begin(), v.end()) - v.begin(); // 1 (5のインデックス)

// 辞書順で次の/前のものに並び替える。返り値は、次の/前のものがない場合にfalse、それ以外はtrueになる。
// 自分で作るとかなりめんどくさいし、非常に便利。
// 全順列を試す場合、再帰するよりもだいたい速い(ただし、枝刈りは難しくなる)。
// 99%くらい以下のdo〜whileの形で使う。
// V<ll> v = { 1, 2, 3 };
// do{
//   // v は ループごとに
//		 { 1, 2, 3 }
// 		 { 1, 3, 2 } 
//       { 2, 1, 3 }
// 		 { 2, 3, 1 }
//		 { 3, 1, 2 }
// 		 { 3, 2, 1 }
//   // になっている。
//   dummy = 1;
// }while(next_permutation(v.begin(), v.end()));
// // ループ後は v = { 1, 2, 3 }

// // 組み合わせを全部試したいときにも使える
// // 3個中2個を選びたい場合は
// // w = { 0, 1, 1 } としておき以下のように出来る。
// do{
//   // w[i] = 1 ならば i 番目のものを選んでいる状態
//   // w[i] = 0 ならば i 番目のものは選んでいない状態
//   dummy = 1;  
// }while(next_permutation(w.begin(), w.end()));

// 総和を簡単に求められる。
// 初期値の型によって結果の型を決めることが出来るのが地味に便利。
// V<ll> v = { 1, 2, 3, 4, 5 };
// V<string> w = { "Competitive", "Programming", "Advent", "Calendar" };
// cout << accumulate(v.begin(), v.end(), 0);   // 15、結果はint
// cout << accumulate(v.begin(), v.end(), 0ll); // 15、結果はlong long
// cout << accumulate(v.begin(), v.end(), 1, multiplies<int>()); // 120、結果はint
// cout << accumulate(w.begin(), w.end(), string()); // "CompetitiveProgrammingAdventCalendar"

// 途中までの和を全部求められる
// この結果を利用してO(1)で部分和を求めることが出来ることなどから利用する場面がありそう
// V<ll> v = { 1, 2, 3, 4, 5 };
// V<ll> w = { 1, 2, 3, 4, 5 };
// // w.size() >= 5 じゃないとダメ
// partial_sum(v.begin(), v.end(), w.begin()); // w = { 1, 3, 6, 10, 15 }
// partial_sum(v.begin(), v.end(), v.begin()); // vに上書きもできる v 

// nCkのコンビネーションの一覧を出してくれる　関数
// vのvectorに、kを変えた時の一覧が配列で出力される。
// void comb(vector<vector<ull> > &v){
//   for(int i = 0;i <v.size(); i++){
//     v[i][0]=1;
//     v[i][i]=1;
//   }
//   for(int k = 1;k <v.size();k++){
//     for(int j = 1;j<k;j++){
//       v[k][j]=(v[k-1][j-1]+v[k-1][j]);
//     }
//   }
// }

// vector<vector<ull> > v(n+1,vector<ull>(n+1,0));
// comb(v);

// map配列  map へのアクセス(countなどのSTL)は、vectorなどに比べてOlogN　の計算量で早い。
//   map<int, int> cnt;
//   for (int x : A) {
//     if (cnt.count(x)) {
// 	  cnt[x]++;
// 	}
//   }

////////////////////////////////   文字列に対して適用   //////////////////////////

//     s = s + t; //連結
//     s == t; //比較
//     s.length(); //長さ
//     cout << s[0] << '\n';    //i番目の文字を参照
//     cout << s.substr(0, 5)<< '\n'; //i番目以降k文字を抽出して得られる文字列
//     cout << s.find("abc")<< '\n';  //sの中に文字列tがあればその先頭のアドレスを返す．なければs.nopsを返却
//        if (UPos != std::string::npos) { ans_s = A -1; }
//     cout << s.replace(0, 3, "zxc")<< '\n'; //i番目以降k文字を文字列tで置換する．tを空文字列にすれば削除の動作

// めちゃ遅い　要注意
//     cout << s.insert(5, "ins")<< '\n'; //i番目の文字の前に文字列tを挿入

// 文字列の辞書順比較
// str <= str2 str > str2 
// min() max() でもOK

// 数値　→　文字列への変換
// auto s = std::to_string(i);

// 数値から、文字列に変換、上位の数字と、下位の数字をペアにして、数値に戻す。
//  auto s = std::to_string(i);
//  ++map[PAIR(s.front() - '0', s.back() - '0')];

// めちゃ遅い　要注意
// 文字列を逆に並べる 引数はイテレータ
//reverse(s.begin() ,s.end());

//  連想配列
//   map<string, int> score;
//   score["Alice"] = 100;
//   score["Dave"] = 95;
//   score["Bob"] = 89;
//  cout << score["Alice"];

