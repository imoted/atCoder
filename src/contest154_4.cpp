#include <bits/stdc++.h>
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
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');


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
  ll B,D,E,F,K,G,H,L,M,N,P,Q,R,W,X,Y,Z;
  double C,A,AF;
  string S,T,U;
  vector<ll> V;
  vector<double> A_list,B_list;
  int ans_s, ans_t;

  cin >> N >> K ;
  REP(i,N){ 
      cin >> P;
      V.pb(P);
  }

  A =0;
  REP(l,V.size()){
    A =0;
    REP(k,V[l]){
      A += V[l] -k;
    }
    C = A / V[l];
    A_list.pb(C);
  }
  REP(m,V.size()){
    REP(n,K){
      AF += V[];
    }
  }
  return 0;
}