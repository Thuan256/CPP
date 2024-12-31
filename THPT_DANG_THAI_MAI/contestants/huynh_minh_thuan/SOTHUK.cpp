#include <bits/stdc++.h>
using namespace std;

#define NAME "SOTHUK"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, m, k;

void solve() {
    cin >> n >> m >> k;

    int num;

    while (m--) {
        cin >> num;
        k += (num <= k);
    }

    if (k > n) cout << -1;
    else cout << k;

    cout << endl;
}

int main() {

    speedup sync

    int test;

    cin >> test;

    while (test--) solve();

    return 0;
}

