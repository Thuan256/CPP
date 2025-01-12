#include <bits/stdc++.h>
using namespace std;

#define NAME "QUA"

#define MAXN 107
#define MAXG 1001
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, s, ans, t, g[MAXN], fac[MAXG];
bool sieves[MAXG];

void eratos() {

    memset(sieves, true, sizeof(sieves));

    sieves[0] = sieves[1] = false;

    for (int p = 2; p * p <= MAXG; p++)
        if (sieves[p])
            for (int i = p * p; i <= MAXG; i += p) {
                sieves[i] = false;
                if (!fac[i]) fac[i] = p;

            }
    return;
}

bool comp (int a, int b) {
    return a > b;
}

bool solve() {

    n = s = ans = t = 0;

    cin >> n;
    if (!n) return false;

    FOR (i, 1, n) cin >> g[i];
    cin >> s;

    vector<pair<int, int>> parts;

    FOR (i, 1, n) {
        parts.emplace_back(g[i], 0);

        int x = g[i];
        int p = fac[x];

        while (p) {
            parts.emplace_back(g[i] / p, 1);

            x /= p;
            p = fac[x];

        }
    }

    sort(parts.rbegin(), parts.rend());

    for (auto part: parts) {
        if (ans + part.fi <= s) {
            ans += part.fi;
            t += part.se;
        }
    }

    cout << ans << " " << t << endl;

    return true;
}

int main() {

    speedup sync
    eratos();

    while (solve()) {};

    return 0;
}

