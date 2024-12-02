#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("MINGROUP1.inp");
    string line;

    getline(inp, line);
    int n = stoi(line);
    int a[n];

    getline(inp, line);
    stringstream ss(line);


    int dp[n];
    int x = 0;

    for (int i = 0; i < n; i++) {
        ss >> a[i];
        x += a[i];

        if (i == 0) dp[i] = a[i];
        else dp[i] = dp[i - 1] + a[i];
    }

    int cur = dp[x-1], _max = dp[x-1];

    for (int i = x; i < n; i++) {
        cur += a[i] - a[i - x];
        _max = max(cur, _max);
    }

    ofstream out("MINGROUP1.out");
    out << (x - _max);
    out.close();
    return 0;

}
