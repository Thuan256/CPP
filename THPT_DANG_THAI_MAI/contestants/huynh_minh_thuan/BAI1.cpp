#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI1"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);


vector<bool> eratos(int n) {
    vector<bool> pri(n + 1, true);
    pri[0] = pri[1] = false;

    for (int p = 2; p * p <= n; p++)
        if (pri[p])
            for (int i = p * p; i <= n; i += p)
                pri[i] = false;

    return pri;
}

vector<bool> sie;
int a[limit], ans = 0;

int main() {

    speedup sync

    int i = 1;

    sie = eratos(1e6);

    while (cin >> a[i]) {

        int x = a[i - 2], y = a[i];

        if (x > 1 && y > 1 && sie[x] && sie[y]) ans = i - 1;

        i++;
    }

    cout << ans;

    return 0;
}

