#include <bits/stdc++.h>
using namespace std;

int dp[1001][2];

int main() {
    ifstream inp("DOREMON.inp");
    ofstream out("DOREMON.out");

    int n,k;
    inp >> n >> k;

    dp[1][1] = dp[1][0] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];

        if (i > k) {
            dp[i][1] -= dp[i - k - 1][1];
        }
    }

    int ans = dp[n][0] + dp[n][1];

    cout << ans;

    inp.close();
    out.close();
    return 0;
}
