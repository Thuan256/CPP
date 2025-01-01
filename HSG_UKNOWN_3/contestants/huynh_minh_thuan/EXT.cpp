#include <bits/stdc++.h>
using namespace std;

#define NAME "EXT"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, a[limit], ans = 0;

int main() {

    speedup sync

    cin >> n;

    if (n < 3) cout << 0;
    else {
        cin >> a[1] >> a[2];

        FOR (i, 3, n) {

            cin >> a[i];

            int val = a[i - 1];

            ans += (val < a[i] && val < a[i - 2]) || (val > a[i] && val > a[i - 2]);
        }

        cout << ans;
    }

    return 0;
}

