#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("CAU4.inp");
    ofstream out("CAU4.out");

    int n, k;
    inp >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) inp >> a[i];

    int i = 0, j = 0;
    ll ans = 0;
    ll sum = 0;

    unordered_map<int, int> dp;
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        sum += a[i];

        int x = sum % k;

        if (dp.find(x) != dp.end()) {
            ans += dp[x];
        }

        dp[x]++;
    }

    out << ans;
    return 0;
}
