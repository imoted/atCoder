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

// #define LOCAL
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

int main(){
  ll A,B,C,D,E,F,K,G,H,L,M,N,P,Q,R,W,X,Y,Z;
  string S,T,U;
  vector<ll> V,A_list,B_list;
  int ans_s, ans_t;

  cin >> N ;
  REP(i,N){ 
      cin >> A;
      A_list.pb(A);
  }
  sort(ALL(A_list));
  B_list = A_list;
  A_list.erase(unique(ALL(A_list)), A_list.end());
  if(B_list == A_list) 
    cYES;
  else
    cNO;
  return 0;
}