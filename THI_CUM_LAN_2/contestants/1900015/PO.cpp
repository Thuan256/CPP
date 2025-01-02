#include <bits/stdc++.h>
using namespace std;

#define NAME "PO"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, s, q, val, cnt[limit], dp[limit];

int main() {

    speedup sync

    cin >> n >> s >> q;

    cnt[0] = 1;

    FOR (i, 1, n) {
        cin >> val;

        FOD(j, s, val) {
            if (dp[j] < dp[j - val] + val) {
                dp[j] = dp[j - val] + val;
                cnt[j] = cnt[j - val];
            } else if (dp[j] == dp[j - val] + val) {
                cnt[j] += cnt[j - val];
            }
        }
    }

    int maxWeight = 0, numWays = 0;

    FOR(j, 0, s) {
        if (dp[j] > maxWeight) {
            maxWeight = dp[j];
            numWays = cnt[j];
        } else if (dp[j] == maxWeight) {
            numWays += cnt[j];
        }
    }

    cout << maxWeight << " " << numWays << "\n";

    return 0;
}

