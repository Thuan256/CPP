#include <bits/stdc++.h>
using namespace std;

#define NAME "SHOPPING"

#define oo 1000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, a, b, x, y, z, dp[oo];

void sub1() {
    FOR (i, 1, n) {
        cin >> x >> y >> z;

        FOD (j, a, y) {
            dp[j] = max(dp[j], dp[j - y] + x);
        }

    }
    cout << dp[a];
}

int main() {

    speedup sync

    cin >> n >> a >> b;

    if (b == 0) sub1();

    return 0;
}
