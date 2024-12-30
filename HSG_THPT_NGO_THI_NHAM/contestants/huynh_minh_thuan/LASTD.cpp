#include <bits/stdc++.h>
using namespace std;

#define NAME "LASTD"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int ans[8] = {1, 1, 3, 1, 9, 9, 7, 9};

void solve() {
    ll n;

    cin >> n;

    cout << ans[(n - n / 2 - n / 5 - n / 10) % 8] << endl;

}

int main() {

    speedup sync

    int test = 3;

    while (test--) solve();

    return 0;
}

