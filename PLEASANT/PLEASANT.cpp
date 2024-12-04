#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[102][2][10];
string num;

int G(string::size_type id, int smaller, int last) {
    if (id == num.size()) return 1;
    if (dp[id][smaller][last] != -1) return dp[id][smaller][last];

    int limit = smaller ? 9 : (num[id] - '0');
    int res = 0;

    for (int d = last; d <= limit; d++) {
        res = (res + G(id + 1, smaller || (d < limit), d)) % mod;
    }

    return dp[id][smaller][last] = res;
}

int count_to(string s) {

    memset(dp, -1, sizeof(dp));
    num = s;
    return G(0, 0, 0);
}

int main() {
    string a, b;
    ifstream inp("PLEASANT.inp");
    ofstream out("PLEASANT.out");

    getline(inp, a);
    getline(inp, b);

    string a_minus_1 = a;
    for (int i = a_minus_1.length() - 1; i >= 0; i--) {
        if (a_minus_1[i] > '0') {
            a_minus_1[i]--;
            break;
        } else {
            a_minus_1[i] = '9';
        }
    }
    if (a_minus_1[0] == '0') a_minus_1.erase(0, 1);

    int result = (count_to(b) - count_to(a_minus_1) + mod) % mod;

    out << result << endl;
    return 0;
}
