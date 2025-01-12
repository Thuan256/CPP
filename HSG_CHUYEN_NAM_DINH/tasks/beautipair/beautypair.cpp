#include <bits/stdc++.h>
#define N 5005

using namespace std;

int n, m, dp[N][N];
char a[N], b[N];

int main() {
    // freopen("beautypair.inp", "r", stdin);
    // freopen("beautypair.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 2;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;

            if (dp[i][j] < 0) dp[i][j] = 0;
        }

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, dp[i][j]);
    
    cout << res <<'\n';
    return 0;
}