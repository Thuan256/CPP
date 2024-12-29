#include <bits/stdc++.h>
using namespace std;

#define NAME "DGROUP"

#define limit 1000007
#define ll long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

ll n, m, k;

int main() {

    speedup sync

    cin >> n >> m >> k;

    ll boy_gr = n / 2;
    ll total_gr = min(boy_gr, m);

    k -= ((m - total_gr) + (n - total_gr * 2));

    ll ans = total_gr - ceil(k / 3.0);

    cout << ans;

    return 0;
}

