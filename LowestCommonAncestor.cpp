const int mxn = 2e5+1, mxk = 19;
vector <ll> adj[mxn], dep(mxn);
vector <vector <int>> par(mxn, vector <int> (mxk, -1));
 
void dfs(int u, int p, int d)
{
    par[u][0] = p;
    dep[u] = d;
    for (int i = 1; i < mxk; ++i)
    {
        int t = par[u][i-1];
        if (t == -1) continue;
        par[u][i] = par[t][i-1];
    }
    for (int v : adj[u])
        if (v != p)
            dfs(v, u, d+1);
}
 
int kthpar(int n, int k)
{
    for (int i = 0; i < mxk; ++i)
        if (k & (1 << i))
            n = par[n][i];
    return n;
}
 
int lca(int a, int b)
{
    if (dep[a] > dep[b]) a = kthpar(a, dep[a]-dep[b]);
    else if (dep[b] > dep[a]) b = kthpar(b, dep[b]-dep[a]);
    if (a == b) return a;
    for (int i = mxk-1; i >= 0; --i)
    {
        if (par[a][i] != par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}
 
