// Longest Common Substring

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("LCS.inp");
    ofstream out("LCS.out");

    string s1,s2;
    getline(inp, s1);
    getline(inp, s2);

    inp.close();

    int m = s1.length();
    int n = s2.length();

    vector<int> pre(n + 1, 0);
    vector<int> cur(n + 1, 0);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = pre[j - 1] + 1;
                ans = max(cur[j], ans);
            } else cur[j] = 0;
        }

        pre = cur;
    }

    out << ans;
    out.close();

    return 0;
}
