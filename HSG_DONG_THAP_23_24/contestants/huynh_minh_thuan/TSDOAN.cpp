#include <bits/stdc++.h>
using namespace std;

#define NAME "TSDOAN"

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

int n, d, a[limit], ps[limit];
double ans;

void sub1() {

    FOR (R, 1, n) {
        cin >> a[R];
        ps[R] = ps[R - 1] + a[R];

        if (R >= d) {

            FOR (L, 1, R - d + 1) {
                ans = max(ans, 1.0 * (ps[R] - ps[L - 1]) / (R - L + 1));
            }
        }
    }

    cout << fixed << setprecision(5) << ans;

    return;
}

int main() {

    speedup sync

    cin >> n >> d;

    if (n <= 5e3 && d <= 5e3) {
        sub1();
    }

    return 0;
}

