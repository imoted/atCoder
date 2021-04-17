#include <atcoder/all>
#include <cstdio>

// int main(int argc, char const *argv[])
// {
    
//     return 0;
// }

using namespace std;
using namespace atcoder;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    fenwick_tree<long long> fw(n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        fw.add(i, a);
    }

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int p, x;
            scanf("%d %d", &p, &x);
            fw.add(p, x);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", fw.sum(l, r));
        }
    }
}

// 長さ NN の配列に対し、

// 要素の 1 点変更
// 区間の要素の総和
// を O(logN) で求めることが出来るデータ構造です。

// 5 5
// 1 2 3 4 5
// 1 0 5
// 1 2 4
// 0 3 10
// 1 0 5
// 1 0 3
