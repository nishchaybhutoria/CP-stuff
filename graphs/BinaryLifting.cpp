#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> adj[n + 1];
    const int lg = 20;
    vector <vector <int>> par(lg, vector <int> (n + 1));
    for (int u = 2; u <= n; ++u) {
        int v;
        cin >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v != p) {
                par[0][v] = u;
                for (int i = 1; i < lg; ++i) {
                    par[i][v] = par[i - 1][par[i - 1][v]];
                }
                dfs(v, u);
            }
        }
    };
    dfs(1, 0);
    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < lg; ++j) {
            if (k & (1 << j)) {
                x = par[j][x];
            }
        }
        cout << (x > 0 ? x : -1) << '\n';
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
