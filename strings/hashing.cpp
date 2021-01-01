/*
Commonly used primes:
1e9+7
1e9+9
998244353
*/
// return odd base in [first, last]
template <typename T>
T get_base(T first, T last)
{
    auto seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    T base = uniform_int_distribution<T>(first, last)(rng);
    return base % 2 ? base : base - 1;
}

// get hash of string in 1 based vector
// be careful of input consisting of A-Z or 1-9
template <typename T>
vector <T> get_hash(string str, const T mod, const T base)
{
    int n = str.size();
    vector <T> _hash(n+1);
    T powers[n+1];
    powers[1] = 1;
    for (int i = 2; i <= n; ++i) powers[i] = powers[i-1] * base % mod;
    for (int i = 1; i <= n; ++i) _hash[i] = (_hash[i-1] + ((str[i-1] - 'a' + 1) * powers[i] % mod)) % mod;
    return _hash;
}

// binary exponentiation
// useful in cases like: (str[i] - str[i - m] + mod) % mod == pat[m] * power(base, i - m, mod) % mod
template <typename T>
T power(T x, T y, const T mod)
{
    T res = 1;
    while (y)
    {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
