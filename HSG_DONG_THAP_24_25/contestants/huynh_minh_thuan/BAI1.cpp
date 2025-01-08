#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI1"

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

ll n, k, ps[oo], a[oo], ans;

int main() {

    speedup sync

    cin >> n >> k;

    FOR (i, 1, n) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }

    FOD (i, n, 1) {
        if ((k - ps[i] % k) <= i) {
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}
