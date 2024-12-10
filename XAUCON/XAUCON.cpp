#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("XAUCON.inp");
    ofstream out("XAUCON.out");

    string s;
    inp >> s;

    vector<char> dp;
    dp.push_back(s[0]);

    for (int i = 1; i < s.length(); i++) {
        if (dp.back() <= s[i]) {
            dp.push_back(s[i]);
        } else {
            int low = lower_bound(dp.begin(), dp.end(), s[i]) - dp.begin();
            dp[low] = s[i];
        }
    }

    out << dp.size();
    out.close();
    return 0;
}
