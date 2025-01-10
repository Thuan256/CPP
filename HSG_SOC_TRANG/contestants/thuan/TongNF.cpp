#include <bits/stdc++.h>
using namespace std;

#define NAME "TongNF"

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

ll m, f[oo], s[oo], x;

int main() {

    speedup sync

    s[1] = f[1] = 1;

    FOR (i, 2, 80) {
        f[i] = f[i - 1] + f[i - 2];
        s[i] = s[i - 1] + f[i];
    }

    cin >> m;

    FOR (i, 1, m) {
        cin >> x;
        cout << s[x] << " ";
    }

    return 0;
}
