// Check the values of N and MOD
// Use brackets properly and don't forget long long

using ll = long long;

const ll MOD = 1e9 + 7;
const ll N = 1e6;

ll fact[N + 1], inv[N + 1];

ll power(ll x, ll y = MOD - 2) {
    ll res = 1ll;
    while (y) {
        if (y & 1LL) res = (res * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1LL;
    }
    return res;
}

void compute() {
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= N; ++i) fact[i] = (fact[i - 1] * i) % MOD;
    inv[N] = power(fact[N]);
    for (ll i = N - 1; i >= 0; --i) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

ll ncr(ll n, ll r) {
    return (((fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
}
