#include <bits/stdc++.h>
using namespace std;

#define NAME "DINNER"

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

ll n, dp[limit], mod = 1'000'000'007;

int main() {

    speedup sync

    cin >> n;

    dp[1] = dp[2] = 1;

    FOR (i, 3, n) {
        dp[i] = (dp[i - 1] + 1ll * (i - 2) * dp[i - 2]) % mod ;
    }

    cout << dp[n];

    return 0;
}

