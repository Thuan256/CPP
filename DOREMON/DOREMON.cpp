#include <bits/stdc++.h>
using namespace std;

int dp[1001][2][1001];

int main() {
    ifstream inp("DOREMON.inp");
    ofstream out("DOREMON.out");

    int n,k;
    inp >> n >> k;

    dp[1][1][1] = dp[1][0][1] = 1;



    inp.close();
    out.close();
    return 0;
}
