#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define mp make_pair
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())

template <typename Container>
void print(Container& container)
{
    auto Start = container.begin(), End = container.end();
    while (Start != End) cout << *(Start++) << " ";
    cout << '\n';
}

template <typename T> using oset = tree <pair <T, T>, null_type, less <pair <T, T>>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void print(T&& t) {cout << t << '\n';}

template <typename T, typename... Args>
void print(T&& t, Args&&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}

inline void solve()
{

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int test = 1; test <= T; ++test)
    {
        // cout << "Case #" << test << ": ";
        solve();
    }
}
