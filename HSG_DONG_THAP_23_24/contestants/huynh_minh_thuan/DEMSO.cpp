#include <bits/stdc++.h>
using namespace std;

#define NAME "DEMSO"

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

ll m, n, q, x;

void sub1() {

    unordered_map<int, int> mp;

    FOR (i, 1, m) {
        FOR (j, 1, n) {
            mp[i * j]++;
        }
    }

    while (q--) cin >> x, cout << mp[x] << endl;
}

void sub2() {

    while (q--) {
        cin >> x;
        ll ans = 0;

        FOR (i, 1, m) {
            if (x % i == 0 && x / i <= n) ans++;
        }
        cout << ans << endl;
    }

}

int main() {

    speedup sync

    cin >> m >> n >> q;

    if (m <= 1e3 && n <= 1e3) sub1();
    else sub2();
    return 0;
}

