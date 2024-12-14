#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    ifstream infile("BAI3.INP");
    ofstream outfile("BAI3.OUT");

    int m, n;
    infile >> m >> n;
    int total = m + n;

    vector<int> a(total + 1), b(total + 1), c(total + 1);

    for (int i = 1; i <= total; ++i) {
        infile >> a[i] >> b[i] >> c[i];
    }

    vector<vector<long long>> dp(total + 1, vector<long long>(m + 1, INF));

    dp[0][0] = 0;

    for (int i = 1; i <= total; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (c[i] == 1) {
                if (j > 0) dp[i][j] = dp[i-1][j-1] + a[i];
            } else if (c[i] == 2) {
                dp[i][j] = dp[i-1][j] + b[i];
            } else {
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[i]);
                dp[i][j] = min(dp[i][j], dp[i-1][j] + b[i]);
            }
        }
    }

    outfile << dp[total][m] << endl;

    return 0;
}
