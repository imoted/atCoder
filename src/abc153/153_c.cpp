#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  long long n, k;
  cin >> n >> k;
  long long h[n];
  for(long long i = 0; i < n; i++)cin >> h[i];
  sort(h, h+n);
  for(long long i = 0; i < k; i++){
    h[max(n-1-i, (long long)0)]=0;
  }
  long long sum = 0;
  for(long long i = 0; i < n-k; i++){
    sum+=h[i];
  }
  cout << sum << endl;
  return 0;
}
