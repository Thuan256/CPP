#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI01"

#define limit 1000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

ll a, b, n, m, ans, mod = 1000000000;

ll fastpow(ll x, ll n) {

    ll ans = 1;

    while (n > 0) {
        if (n % 2 == 1) ans *= x;

        ans %= mod;
        x *= x;
        x %= mod;
        n /= 2;
    }

    return ans;
}

int main() {

    speedup sync

    cin >> a >> b >> n >> m;

    cout << fastpow(a, n) + fastpow(b, m);

    return 0;
}

