#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI3"

#define limit 1000007
#define ll long long
#define FOD(i,b,a) for(int i = (int)b; i >= (int)a; i--)
#define FOR(i,a,b) for(int i = (int)a; i <= (int)b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int main() {

    speedup sync

    int n, m;
    cin >> n >> m;

    int a[n + 1];
    ll ps[n + 1];

    ps[0] = 0;

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }

    for (int L = 0; L <= m; L++) {
        ans = max(ans, ps[L] + (ps[n] - ps[n - (m - L)]));
    }

    cout << ans;

    return 0;
}

