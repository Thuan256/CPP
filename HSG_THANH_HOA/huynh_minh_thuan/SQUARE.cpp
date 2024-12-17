#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("SQUARE.inp");
    ofstream out("SQUARE.out");

    int m, n, k, i, j, ans = INT_MIN, min_freq = INT_MAX;
    inp >> m >> n >> k;

    vector<vector<int>> a(m + 1, vector<int>(n + 1, 0)), dp(m + 1, vector<int>(n + 1, 0));
    vector<vector<unordered_set<int>>> c(m - k + 1, vector<unordered_set<int>>(n - k + 1));

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            inp >> a[i][j];

            dp[i][j] = a[i][j] - dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1];
        }
    }

    for (i = m; i <= m; i++) {
        for (j = n; j <= n; j++) {
            int sum = dp[i][j] + dp[i - 1][j - 1] - dp[i - m][j] - dp[i][j - n];

            unordered_set<int> freq;

            for (int x = i - m; x <= i; x++) {
                for (int y = j - n; y <= j; y++) {
                    freq.insert(a[x][y]);
                }
            }

            cout << freq.size() << endl;

            if (freq.size() <= min_freq) {
                min_freq = freq.size();
                ans = sum;
            }
        }
    }

    cout << ans;

}
