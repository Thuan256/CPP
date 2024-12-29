#include <bits/stdc++.h>
using namespace std;

#define NAME "GAME"

#define limit 1000007
#define ll long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

ll n, a[limit];
ll ans = 0;

int main() {

    speedup sync

    cin >> n;

    FOR (i, 1, n) cin >> a[i];

    if (n >= 3) {
        ll s1 = a[1];
        ll s2 = a[1] + a[2];
        ll s3 = max(max(a[1] + a[2], a[2] + a[3]), a[1] + a[3]);

        ans = s3;

        FOR (i, 4, n) {
            ans = max(max(s3, s2 + a[i]), s1 + a[i - 1] + a[i]);

            s1 = s2;
            s2 = s3;
            s3 = ans;
        }

    } else ans = accumulate(begin(a), end(a), 0);

    cout << ans;

    return 0;
}

