#include <bits/stdc++.h>
using namespace std;

#define NAME "GARBAGE"

#define oo 1007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int m, n, ans, path[oo], a[oo][oo], dp[oo][oo], trace[oo][oo];

int main() {

    speedup sync

    cin >> m >> n;

    FOR (i, 1, m) {
        FOR (j, 1, n) {
            cin >> a[i][j];

            if (i >= 2) {

                int prev;

                if (dp[i - 1][j - 1] > dp[i - 1][j] && dp[i - 1][j - 1] > dp[i - 1][j + 1]) {
                    prev = dp[i - 1][j - 1];
                    trace[i][j] = j - 1;
                } else if (dp[i - 1][j] > dp[i - 1][j + 1]) {
                    prev = dp[i - 1][j];
                    trace[i][j] = j;
                } else {
                    prev = dp[i - 1][j + 1];
                    trace[i][j] = j + 1;
                }

                dp[i][j] = prev + a[i][j];

                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                    path[m] = j;
                }
            } else dp[i][j] = a[i][j];
        }
    }

    cout << ans << endl;

    FOD (i, m, 2) {
        path[i - 1] = trace[i][path[i]];
    }

    FOR (i, 1, m) cout << path[i] << endl;

    return 0;
}

