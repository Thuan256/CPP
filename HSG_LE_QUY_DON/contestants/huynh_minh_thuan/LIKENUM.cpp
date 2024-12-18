#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[20][2][100000][20];
vector<int> digits;

ll solve(int pos, int is_tight, int mod, int len, int x, int k, int base) {
    if (pos == digits.size()) {
        return (len >= k && mod == x);
    }

    if (dp[pos][is_tight][mod][len] != -1)
        return dp[pos][is_tight][mod][len];

    ll ans = 0;
    int limit = is_tight ? digits[pos] : 9;

    for (int d = 0; d <= limit; d++) {
        ans += solve(pos + 1,
                     is_tight && (d == limit),
                     (mod * 10 + d) % base,
                     len + 1,
                     x, k, base);
    }

    return dp[pos][is_tight][mod][len] = ans;
}

ll countNumbersWithLastX(const string &n, int x) {
    digits.clear();
    for (char c : n) {
        digits.push_back(c - '0');
    }

    int k = to_string(x).size();
    int base = 1;
    for (int i = 0; i < k; i++) base *= 10;

    memset(dp, -1, sizeof(dp));
    return solve(0, 1, 0, 0, x, k, base);
}

int main() {
    ifstream inp("LIKENUM.INP");
    ofstream out("LIKENUM.OUT");

    string m;
    int x;
    inp >> x >> m;

    ll result = countNumbersWithLastX(m, x);

    if (stoll(m) >= x) {
        result -= 1;
    }

    out << result << endl;

    return 0;
}
