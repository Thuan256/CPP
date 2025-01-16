#include <bits/stdc++.h>
using namespace std;

#define NAME "SKP"

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

int n;
ll b[oo], h[oo], f[oo];
const ll INF = 1e18;

void sub1() {
    h[0] = INF;
    b[0] = 0;

    memset(f, -INF, sizeof(s));

    FOR (i, 1, n) {
        int mn = 0;
        FOD (j, i, 1) {
            if (h[mn] >= h[j]) mn = j;
            f[i] max(f[i], f[j - 1] + b[mn]);
        }
    }
}

ll st[2 * oo], lazy[2 * oo];

int main() {

    speedup sync

    return 0;
}

