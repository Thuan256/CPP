#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inp("FOOD.inp");
    ofstream out("FOOD.out");

    int n, m, ans = 0;
    inp >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0)), dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            inp >> a[i - 1][j - 1];

            int prev = (i < n) ? max(dp[i][j - 1], dp[i - 1][j]) : dp[i - 1][j];

            dp[i][j] = prev + a[i - 1][j - 1];
            ans = max(ans, dp[i][j]);
        }
    }

    out << ans;
    inp.close();
    out.close();

    return 0;
}
