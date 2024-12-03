#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream inp("NUMBERS.inp");
    ofstream out("NUMBERS.out");
    string line;

    getline(inp, line);
    int n = stoi(line);
    int a[n];

    getline(inp, line);
    inp.close();

    stringstream ss(line);
    vector<vector<int>> dp = {{0, 0}, {0, 0}};

    for (int i = 0; i < n; i ++) {
        ss >> a[i];

        dp[1][a[i] % 2]++;
    }

    int i = 0;

    do {

        int x = a[i] % 2;

        dp[1][x]--;

        if (dp[0][0] == dp[1][0] || dp[0][1] == dp[1][1]) {
            out << i;
            out.close();
            return 0;
        }

        dp[0][x]++;

        i++;
    } while (i < n - 1);


    out << -1;
    out.close();
    return 0;
}
