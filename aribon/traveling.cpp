#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr ll  MOD = (1e9+7);
constexpr int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
constexpr int lcm(int a, int b) { return a / gcd(a, b) * b; }

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll factorial(ll n, ll m=2) {
    // calculate n!
    m = max(2LL, m);
    ll rtn = 1;
    for (ll i=m; i<=n; i++) {
        rtn = (rtn * i) % MOD;
    }
    return rtn;
}
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, k, a, b; cin >> n >> m >> k >> a >> b;
    a--; b--;
    vector<int> t(n);
    vector<vector<int>> d(m, vector<int>(m, -1));
    vector<vector<double>> dp(1 << n, vector<double>(m, INF));
    rep(i, n) cin >> t[i];
    rep(i, k) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        d[u][v] = w;
        d[v][u] = w;
    }
    // initialization
    dp[(1<<n)-1][a] = 0;
    double res = INF;
    for (int S = (1<<n)-1; S >= 0; S--) {
        res = min(res, dp[S][b]);
        rep(v, m) {
            rep(i, n) {
                if (S >> i & 1) {
                    rep(u, m) {
                        if (d[v][u] >= 0) {
                            dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[v][u]/t[i]);
                        }
                    }
                }
            }
        }
    }
    if (res == INF) cout << "Inpossible";
    else cout << res << endl;
    
}