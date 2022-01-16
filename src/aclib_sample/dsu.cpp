#include <atcoder/dsu>
#include <iostream>
#include <cstdio>

using namespace std;
using namespace atcoder;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    dsu d(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        scanf("%d %d %d", &t, &u, &v);
        if (t == 0) {
            d.merge(u, v); // 辺 (a, b) を足します。
            cout << d.leader(u);  // 頂点 a の属する連結成分の代表元を返します。
        } else {
            if (d.same(u, v)) { // 頂点 a, b が連結かどうかを返します。
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}
