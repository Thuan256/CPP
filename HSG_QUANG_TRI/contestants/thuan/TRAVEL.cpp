#include <bits/stdc++.h>
using namespace std;

#define NAME "TRAVEL"

#define oo 1000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, Q, d[oo], x, y, z;

int main() {

    speedup sync

    cin >> n >> Q;
    FOR (i, 1, n) cin >> d[i];

    while (Q--) {

        int ans = INT_MAX;

        cin >> x >> y;

        FOR (z, 1, n) {
            ans = min(ans, max(abs(d[z] - d[x]), abs(d[z] - d[y])));
        }

        cout << ans << endl;
    }

    return 0;
}

