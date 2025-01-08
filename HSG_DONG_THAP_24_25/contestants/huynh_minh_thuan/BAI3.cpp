#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI3"

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

string s;
int q, l, r, u, v;

int comp(string a, string b) {
    // a < b : 0
    // a > b : 1
    // a == b : 2

    if (a == b) return 2;

    int m = a.size() <= b.size() ? a.size() : b.size();

    FOR (i, 0, m - 1) {
        if (a[i] < b[i]) return 0;
        else if (a[i] > b[i]) return 1;
    }

    return (a.size() > b.size()) ? 1 : 0;
}

int solve() {
    cin >> l >> r >> u >> v;

    int L, R;

    if (r - l <= v - u) {

        L = l;
        R = r;

        while (L <= R) {
            if (s[L - 1] < s[u + L - l - 1]) return 0;
            else if (s[L - 1] > s[u + L - l - 1]) return 1;

            L++;
        }

        if (r - l < v - u) return 0;

        return 2;
    } else {
        L = u;
        R = v;

        while (L <= R) {
            if (s[L - 1] < s[l + L - u - 1]) return 0;
            else if (s[L - 1] > s[l + L - u - 1]) return 1;

            L++;
        }

        return 1;
    }
}

int main() {

    speedup sync

    cin >> s >> q;

    while (q--) {
        cout << solve() << endl;
    }

    return 0;
}
