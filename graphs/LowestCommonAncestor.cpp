#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> adj[n + 1], dep(n + 1);
    const int lg = 21;
    vector <vector <int>> up(lg, vector <int> (n + 1));
    for (int u = 2; u <= n; ++u) {
        int v;
        cin >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        up[0][u] = v;
    }
    function <void(int, int, int)> dfs = [&](int u, int p, int d) {
        dep[u] = d;
        for (int v : adj[u]) {
            if (v != p) {
                for (int i = 1; i < lg; ++i) {
                    up[i][v] = up[i - 1][up[i - 1][v]];
                }
                dfs(v, u, d + 1);
            }
        }
    };
    dfs(1, 0, 1);
    function <int(int, int)> kthpar = [&](int u, int k) {
        int v = u;
        for (int i = 0; i < lg; ++i) {
            if (k & (1 << i)) {
                v = up[i][v];
            }
        }
        return v;
    };
    function <int(int, int)> lca = [&](int u, int v) {
        if (dep[u] > dep[v]) {
            swap(u, v);
        }
        if (dep[u] != dep[v]) {
            v = kthpar(v, dep[v] - dep[u]);
        }
        if (u == v) {
            return u;
        }
        for (int i = lg - 1; ~i; --i) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }
        return up[0][u];
    };
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
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
