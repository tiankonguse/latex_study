\\mod must be a prime
typedef long long ll;
ll const mod = 1000000007;
int const maxn = 100100;
ll fac[maxn], inv[maxn];
ll C(int n, int m) {
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
ll powMod(ll a, ll b) {
    ll ret = 1LL;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void Cinit() {
    fac[0] = inv[0] = 1LL;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = powMod(fac[i], mod - 2);
    }
}
