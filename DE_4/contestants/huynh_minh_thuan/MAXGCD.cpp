#include <bits/stdc++.h>
using namespace std;

#define NAME "MAXGCD"

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

ll a, b, mod = 1e9 + 7;

int facmod(int x) {
    ll ans = 1;
    FOR (i, 1, x) {
        ans = (ans * i) % mod;
    }

    return ans;
}

int main() {

    speedup sync

    cin >> a >> b;

    cout << facmod(min(a, b));

    return 0;
}

