#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define F first
#define S second
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T> using oset = tree <pair <T, T>, null_type, less <pair <T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
void ckmin(T& a, const T b) {a = min(a, b);}
 
template <typename T>
void ckmax(T& a, const T b) {a = max(a, b);}
 
template <typename T>
vector <T> sieve(T n) {
    vector <T> f(n+1, 1), res;
    for (T i = 2; i <= n; ++i)
        for (T j = i; j <= n; j += i)
            ++f[j];
    for (T i = 2; i <= n; ++i)
        if (f[i] == 2)
            res.eb(i);
    return res;
}
 
template <typename T>
T power(T a, T b) {
    T res = 1;
    while (b)
    {
        if (b & 1) res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}
 
template <typename T>
void print(vector <T> v) {
    for (T i : v) cout << i << " ";
    cout << '\n';
}
 
template <typename T>
void print(vector <vector <T>>& v) {
    for (vector <T>& vv : v) {
        for (T& i : vv)
            cout << i << " ";
        cout << '\n';
    }
}
 
template <typename T>
void read(vector <T>& v) {for (T& i : v) cin >> i;}
 
template <typename T>
void read(T&& t) {cin >> t;}
 
template <typename T, typename... Args>
void read(T&& t, Args&&... args)
{
    cin >> t;
    read(forward<Args>(args)...);
}
 
template <typename T>
void print(T&& t) {cout << t << '\n';}
 
template <typename T, typename... Args>
void print(T&& t, Args&&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}
 
void usaco(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(name.size())
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".txt").c_str(), "w", stdout);
    }
}
 
inline void solve()
{
    
}
 
int32_t main()
{
    usaco();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
