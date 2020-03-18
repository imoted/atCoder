/**
 *    author:  tourist
 *    created: 03.11.2019 19:31:34       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  struct State {
    int onlyI;
    int onlyD;
    int both;
    int val;
    int val_worse;
  };
  auto UpdateBoth = [&](State& s, int dp, int dpval) {
    if (dp < s.both) {
      if (dp == s.both - 1) {
        s.val_worse = min(s.val, dpval);
      } else {
        s.val_worse = dpval;
      }
      s.val = dpval;
      s.both = dp;
    } else {
      if (dp == s.both) {
        s.val = min(s.val, dpval);
      }
      if (dp == s.both + 1) {
        s.val_worse = min(s.val_worse, dpval);
      }
    }
  };
  State x;
  x.onlyI = 1;
  x.onlyD = 1;
  x.both = 2;
  x.val = 0;
  x.val_worse = 0;
  for (int i = 1; i < n; i++) {
    State y;
    y.onlyI = y.onlyD = min(min(x.onlyI, x.onlyD), x.both) + 1;
    y.both = y.onlyI + 1;
    y.val = y.val_worse = 0;
    { // onlyI -> onlyI
      if (a[i] >= a[i - 1]) {
        y.onlyI = min(y.onlyI, x.onlyI);
      }
    }
    { // onlyI -> both
      if (a[i] >= a[i - 1]) {
        UpdateBoth(y, x.onlyI + 1, a[i - 1]);
      }
    }
    { // onlyD -> onlyD
      if (a[i] <= a[i - 1]) {
        y.onlyD = min(y.onlyD, x.onlyD);
      }
    }
    { // onlyD -> both
      UpdateBoth(y, x.onlyD + 1, max(0, a[i] - a[i - 1]));
    }
    { // both -> onlyI
      if (a[i] >= x.val) {
        y.onlyI = min(y.onlyI, x.both);
      }
    }
    { // both -> onlyD
      if (a[i] <= a[i - 1] - x.val) {
        y.onlyD = min(y.onlyD, x.both);
      }
    }
    for (int rot = 0; rot < 2; rot++) {
      { // both -> both, keep
        int curI = x.val;
        int curD = a[i - 1] - x.val;
        if (a[i] < curI + curD) {
          curD -= (curI + curD) - a[i];
        } else {
          curI += a[i] - (curI + curD);
        }
        if (curD >= 0 && curI >= 0) {
          UpdateBoth(y, x.both, curI);
        }
      }
      { // both -> both, break I
        int curI = 0;
        int curD = a[i - 1] - x.val;
        if (a[i] < curI + curD) {
          curD -= (curI + curD) - a[i];
        } else {
          curI += a[i] - (curI + curD);
        }
        if (curD >= 0 && curI >= 0) {
          UpdateBoth(y, x.both + 1, curI);
        }
      }
      { // both -> both, break D
        int curI = x.val;
        int curD = (int) 1.01e9;
        if (a[i] < curI + curD) {
          curD -= (curI + curD) - a[i];
        } else {
          curI += a[i] - (curI + curD);
        }
        if (curD >= 0 && curI >= 0) {
          UpdateBoth(y, x.both + 1, curI);
        }
      }
      x.both += 1;
      x.val = x.val_worse;
    }
    x = y;
  }
  cout << min(min(x.onlyI, x.onlyD), x.both) << '\n';
  return 0;
}
