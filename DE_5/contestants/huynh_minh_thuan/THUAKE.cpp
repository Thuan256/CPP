#include <bits/stdc++.h>
using namespace std;

#define NAME "THUAKE"

#define oo 100007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n = 1, diff, a[oo], x[oo], s[3];

int _find(int i) {
    FOR (k, 1, n) {
        if (x[k] == i) {
            if (diff > abs(s[i] - s[3 - i] - 2 * a[k])) {
                return k;
            }
        }
    }
    return 0;
}

void trans(int i, int k) {
    diff = abs(s[i] - s[3 - i] - 2 * a[k]);
    x[k] = 3 - i;
    s[i] -= a[k];
    s[3 - i] += a[k];
}

bool cal(int &u, int &v) {
    FOR (i, 1, n) {
        if (x[i] == 1) {
            FOR (j, 1, n) {
                if (x[j] == 2) {
                    if (diff > abs(s[1] - s[2] - 2 * (a[i] - a[j]))) {
                        u = i;
                        v = j;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void solve() {
    bool stop = false;

    while (!stop) {
        stop = true;

        FOR (i, 1, 2) {
            int k = _find(i);

            if (k) {
                trans(i, k);
                stop = false;
                break;
            }
        }

        if (stop) {

            int u, v;

            if (cal(u, v)) {
                trans(1, u);
                trans(2, v);
                stop = false;
            }
        }
    }
}
int main() {

    speedup sync

    while (cin >> a[n]) {
        diff = s[1] += a[n];
        x[n] = 1;
        n++;
    }

    --n;

    solve();

    cout << s[1] << " " << s[2] << " " << diff << '\n';

    FOR (i, 1, n) if (x[i] == 1) cout << i << " ";
    cout << '\n';
    FOR (i, 1, n) if (x[i] == 2) cout << i << " ";

    return 0;
}

