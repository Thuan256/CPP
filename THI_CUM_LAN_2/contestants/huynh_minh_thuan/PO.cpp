#include <bits/stdc++.h>
using namespace std;

#define NAME "PO"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, s, q, val, a[limit], cnt[limit], dp[limit];

int main() {

    speedup sync

    cin >> n >> s >> q;

    cnt[0] = 1;

    FOR (i, 1, n) {
        cin >> a[i];

        FOD(j, s, a[i]) {

            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }

    cout << dp[s] << endl;

    if (q == 2) {
        FOR (i, 1, n) {
            FOD (j, s, a[i]) {
                if (dp[j] == dp[j - a[i]] + a[i]) {
                    cnt[j] += cnt[j - a[i]];
                }
            }
        }

        cout << cnt[dp[s]];
    }

    return 0;
}

