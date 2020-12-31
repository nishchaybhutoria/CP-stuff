template <typename T>
void dijkstra(T src, vector <T>& d, vector <T>& p)
{
    d[src] = 0;
    using pll = pair <T, T>;
    priority_queue <pll, vector <pll>, greater <pll>> q;
    q.emplace(make_pair(0, src));
    while (!q.empty())
    {
        T u = q.top().S;
        T du = q.top().F;
        q.pop();
        if (du != d[u]) continue;
        for (auto edge : adj[u])
        {
            T v = edge.F;
            T dv = edge.S;
            if (d[u] + dv < d[v])
            {
                d[v] = d[u] + dv;
                p[v] = u;
                q.emplace(make_pair(d[v], v));
            }
        }
    }
}
