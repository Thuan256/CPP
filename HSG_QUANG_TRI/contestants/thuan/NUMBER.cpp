#include <bits/stdc++.h>
using namespace std;

#define NAME "NUMBER"

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

ll L, R, ans;

vector<bool> eratos(int n) {
    vector<bool> pri(n + 1, 1);

    pri[0] = pri[1] = 0;

    for (int p = 2; p * p <= n; p++)
        if (pri[p])
            for (int i = p * p; i <= n; i += p)
                pri[i] = 0;
    return pri;
}

int main() {

    speedup sync

    cin >> L >> R;

    vector<bool> sie = eratos(1e7);

    for (ll i = ceil(sqrt(L)); i * i <= R; i++) {
        ans += sie[i];
    }

    cout << ans;

    return 0;
}

