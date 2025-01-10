#include <bits/stdc++.h>
using namespace std;

#define NAME "VuonNha"

#define oo 1007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

ll m, n, p, q, a[oo][oo], s[oo][oo], ans = LLONG_MAX, ans_i, ans_j;

int main() {

    speedup sync

    cin >> m >> n >> p >> q;

    FOR (i, 1, m) {
        FOR (j, 1, n) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
        }
    }


    FOR (i, p, m) {
        FOR (j, q, n) {
            ll sum = s[i][j] - s[i - p][j] - s[i][j - q] + s[i - p][j - q];
            if (sum < ans) {
                ans = sum;
                ans_i = i - p + 1;
                ans_j = j - q + 1;
            }
        }
    }

    cout << ans << endl << ans_i << " " << ans_j;

    return 0;
}
