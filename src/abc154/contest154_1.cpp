#include <bits/stdc++.h>
// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01040_source.html
using namespace std;
#define REP(i, n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i, n) for(ll i=(ll)(n-1);i>=0;i--)
#define FOR(i, a, b) for(ll i=(ll)(a); i<=(ll)(b); i++)
#define RFOR(i, a, b) for(ll i=(ll)(a);i>=(ll)(b); i--)
#define pb push_back // 配列の最後にappendする
#define mp make_pair 
#define ALL(x) (x).begin(),(x).end()   // accumulateする場合、最初から最後までということか？
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef vector<int> veci;
typedef vector<long long> vecl;

ll A,B,C,D,E,F,K,G,H,L,M,N,P,Q,R,W,X,Y,Z;
string S,T, U;
vector<ll> V;
int ans_s, ans_t;

// #define LOCAL
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

int main(){
//    pair <int,int> foo;
//    vector<int> vec{ 1, 2, 3 };

//    ll ans = 1;
  // int x =10;
  // int y =5;
  // swap(x,y);
  // cout << min(x,y)<< '\n';
  // cout << max(x,y)<< '\n';

  // cin >> N >> K;
  // REP(i,N){
  //   cin >> X;
  //   V.pb(X);
  // }

    cin >> S >> T;
    cin >> A >> B;
    cin >> U;
    ans_s = A;
    ans_t = B;

    int UPos = S.find(U);
    if (UPos != std::string::npos) {
      ans_s = A -1;
    }
    UPos = T.find(U);
    if (UPos != std::string::npos) {
      ans_t = B -1;
    }

 cout << ans_s << " " << ans_t;


  // auto result = find(ALL(S), 10);
  
  // if (result != S.end()) {
  //   ans_s = A -1;
  // }

  //   cout << s << endl;
  //   s = s + t; //連結
  //   s == t; //比較
  //   s.length(); //長さ
  //   cout << s[0] << '\n';    //i番目の文字を参照
  //   cout << s.substr(0, 5)<< '\n'; //i番目以降k文字を抽出して得られる文字列
  //   cout << s.find("abc")<< '\n';  //sの中に文字列tがあればその先頭のアドレスを返す．なければs.nopsを返却
  //   cout << s.replace(0, 3, "zxc")<< '\n'; //i番目以降k文字を文字列tで置換する．tを空文字列にすれば削除の動作
  //   cout << s.insert(5, "ins")<< '\n'; //i番目の文字の前に文字列tを挿入

  //   vector<int> a{1,2,3,4,5};
  //   cout << a.size()<< '\n'; //aの大きさ
  //   cout << a[3]<< '\n'; //i番目の要素にアクセス
  //   cout << a.front()<< '\n';  //先頭を参照
  //   cout << a.back()<< '\n';   //末尾を参照
  //   a.push_back(10);  //末尾に要素を追加
  //   // cout << a << '\n';
  //   a.pop_back();   //末尾の要素を削除
  //   // cout << a << '\n';

  //   FOR(i,0,10){
  //       //   vec.push_back(i);
  //       a.pb(i);
  //   }
  //   // reverse(a, a.end());
  //   sort(ALL(a));
  //   cout << binary_search(a.begin(), a.end(), 20)<< '\n'; //trueかfalseを返す
  //   vector<int>::iterator lit = lower_bound(a.begin(), a.end(), 5);   //x以上の値が初めて現れる位置のイテレータを返す
  //   vector<int>::iterator uit = upper_bound(a.begin(), a.end(), x);   //xより大きい値が初めて現れる位置のイテレータを返す 
	// if(lit != a.end() && lit != uit)
	// 	cout << uit - lit << '\n';	// この場合, ult - lit は vc 中の x の個数になる    
  return 0;
}