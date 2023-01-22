#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,popcnt")

#include <bits/stdc++.h>

using namespace std;
 
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mp make_pair
#define F first
#define S second
#define eb emplace_back
#define pb push_back
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())

struct Edge {
    int u, v;
    int64_t w;
};

vector <int> par, sz;
vector <Edge> edges;

int get(int v) {
    return par[v] = (par[v] == v ? v : get(par[v]));
}

void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

bool same_set(int u, int v) {
    return get(u) == get(v);
}

inline void solve() {
    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    sz.resize(n + 1);
    edges.resize(m);
    auto comp = [&](Edge &a, Edge &b) {
        return a.w < b.w;
    };
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        int64_t w;
        cin >> u >> v >> w;
        edges[i] = Edge{u, v, w};
    }
    sort(all(edges), comp);
    int64_t W = 0;
    for (int i = 0; i < m; ++i) {
        if (!same_set(edges[i].u, edges[i].v)) {
            unite(edges[i].u, edges[i].v);
            W += edges[i].w;
        }
    }
    cout << W << '\n';
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 1;
    // cin >> tests;
    for (int _ = 0; _ < tests; ++_) {
        // cout << "Case #" << _ + 1 << ": ";
        solve();
    }
}