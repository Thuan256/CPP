// Longest Common Substring

#include <bits/stdc++.h>

using namespace std;

int dp[1007][1007];

int main() {
    ifstream inp("LCS.inp");
    ofstream out("LCS.out");

    string s1,s2;
    getline(inp, s1);
    getline(inp, s2);

    inp.close();

    int m = s1.length();
    int n = s2.length();

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    out << dp[m][n];
    out.close();

    return 0;
}
