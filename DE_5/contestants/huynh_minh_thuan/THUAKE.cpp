#include <bits/stdc++.h>
using namespace std;

#define NAME "THUAKE"

#define limit 1000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n = 1, a[limit], sum;
bool dp[limit], selected[limit];
vector<ll> trace[limit];

int main() {

    speedup sync

    while (cin >> a[n]) sum += a[n++];

    n--;

    dp[0] = true;


    sort(a, a + n);

    FOR (i, 1, n) {
        FOD (j, sum / 2, a[i]) {
            if (dp[j - a[i]]) {
                dp[j] = true;
                trace[j] = trace[j - a[i]];
                trace[j].pb(i);
            }
        }
    }

    int p1, p2, diff;

    FOD (i, sum / 2, 0) {
        if (dp[i]) {

            p1 = i;
            p2 = sum - p1;
            diff = abs(p1 - p2);

            break;
        }
    }

    cout << p1 << " " << p2 << " " << diff << endl;

    for (int idx: trace[p1]) cout << idx << " ", selected[idx] = true;

    cout << endl;

    FOR (i, 1, n) if (!selected[i]) cout << i << " ";

    return 0;
}

