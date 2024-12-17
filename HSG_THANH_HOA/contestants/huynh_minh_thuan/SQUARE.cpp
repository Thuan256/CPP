#include <bits/stdc++.h>
#define ll long long

using namespace std;

void update_freq(unordered_map<int, int>& freq, int& uniq, int val, int delta) {
    freq[val] += delta;
    if (freq[val] == 0) uniq--;
    if (freq[val] == 1 && delta == 1) uniq++;
}

int main() {
    ifstream inp("SQUARE.inp");
    ofstream out("SQUARE.out");

    int m, n, k, i, j, x, y, ans = INT_MAX, min_uniq = INT_MAX;
    inp >> m >> n >> k;

    vector<vector<int>> a(m + 1, vector<int>(n + 1, 0)), dp(m + 1, vector<int>(n + 1, 0));

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            inp >> a[i][j];

            dp[i][j] = a[i][j] - dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1];
        }
    }

    for (i = k; i <= m; i++) {

        unordered_map<int, int> freq;
        int uniq = 0;

        for (x = i - k + 1; x <= i; ++x)
            for (y = 1; y <= k; ++y)
                update_freq(freq, uniq, a[x][y], 1);


        for (int j = k; j <= n; j++) {
            int sum = dp[i][j] + dp[i - k][j - k] - dp[i - k][j] - dp[i][j - k];

            if (uniq < min_uniq || (uniq == min_uniq && sum < ans)) {
                min_uniq = uniq;
                ans = sum;
            }

            if ( j < n) {
                for (x = i - k + 1; x <= i; x++) {

                    int last_val = a[x][j - k + 1], next_val = a[x][j + 1];

                    update_freq(freq, uniq, last_val, -1);
                    update_freq(freq, uniq, next_val, 1);
                }
            }
        }

    }

    out << ans;
    out.close();
    inp.close();

    return 0;
}

