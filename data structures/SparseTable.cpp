#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n, q;
    cin >> n >> q;
    const int lg = 21, maxn = 2e5;
    vector <vector <int64_t>> sparse_table(lg, vector <int64_t> (maxn + 1));
    vector <int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sparse_table[0][i] = a[i];
    }
    for (int i = 1; i < lg; ++i) {
        for (int j = 1; j <= n; ++j) {
            sparse_table[i][j] = sparse_table[i - 1][j] + sparse_table[i - 1][j + (1 << (i - 1))];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int64_t ans = 0;
        for (int i = lg - 1; ~i; --i) {
            if ((1 << i) <= r - l + 1) {
                ans += sparse_table[i][l];
                l += (1 << i);
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 1;
    // cin >> tests;
    for (int _ = 0; _ < tests; ++_) {
        solve();
    }
}
