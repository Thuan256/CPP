#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("BAI5.inp");
    string line;
    getline(inp, line);

    int n = stoi(line);
    int a[n];

    getline(inp, line);
    stringstream ss(line);

//    vector<vector<int>> dp(2, vector<int>(n, 0));

//    ss >> dp[1][0];
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ss >> a[i];

//        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - a[i]);
//        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            ans += a[i];
        else
            ans += max(0, a[i] - a[i + 1]);
    }

    ofstream out("BAI5.out");
//    out << max(dp[0][n - 1], dp[1][n - 1]);
    out << ans;
    out.close();

    return 0;
}
