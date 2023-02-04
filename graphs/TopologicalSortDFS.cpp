#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> pairs(m);
    vector <int> adj[n + 1], vis(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        pairs[i] = make_pair(u, v);
        adj[u].emplace_back(v);
    }
    vector <int> topo_sort;
    function <void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
        topo_sort.emplace_back(u);
    };
    function <void()> compute = [&]() {
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        reverse(topo_sort.begin(), topo_sort.end());
    };
    compute();
    vector <int> id(n + 1);
    for (int i = 0; i < n; ++i) {
        id[topo_sort[i]] = i;
    }
    bool ok = 1;
    for (int i = 0; i < m; ++i) {
        ok &= (id[pairs[i].first] < id[pairs[i].second]);
    }
    if (!ok) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int v : topo_sort) {
            cout << v << " ";
        }
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
