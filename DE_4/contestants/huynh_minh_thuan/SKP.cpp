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
const int m = 1 << 21;

ll h[oo], b[oo], f[oo];
const ll INF = 1e18;

void sub1() {
    h[0] = INF;
    b[0] = 0;

    fill(f + 1, f + n + 1, -INF);

    FOR (i, 1, n) {
        int mn = 0;
        FOD (j, i, 1) {
            if (h[mn] >= h[j]) mn = j;
            f[i] = max(f[i], f[j - 1] + b[mn]);
        }
    }
}

ll st[m], lazy[m];

void down(int idx) {
    ll tmp = lazy[idx];
    if (tmp == 0) return;

    st[2 * idx] += tmp;
    lazy[2 * idx] += tmp;

    st[2 * idx + 1] += tmp;
    lazy[2 * idx + 1] += tmp;

    lazy[idx] = 0;
}

void update(int idx, int lx, int rx, int l, int r, ll x) {
    if (lx > r || rx < l) return;
    if (lx >= l && rx <= r) {
        if (st[idx] == -INF) st[idx] = x;
        else st[idx] += x;

        lazy[idx] += x;
        return;
    }

    down(idx);

    int mid = (lx + rx) / 2;
    update(2 * idx, lx, mid, l, r, x);
    update(2 * idx + 1, mid + 1, rx, l, r, x);

    st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}

void update_point(int idx, int lx, int rx, int pos, ll x) {
    if (lx == rx) {
        lazy[idx] = x;
        st[idx] = x;
        return;
    }

    down(idx);

    int mid = (lx + rx) / 2;

    if (pos <= mid) update_point(2 * idx, lx, mid, pos, x);
    else update_point(2 * idx + 1, mid + 1, rx, pos, x);

    st[idx] = max(st[2 * idx], st[2 * idx + 1]);
}

void sub2() {
    stack<int> q;
    h[0] = -INF;

    fill(st, st + m, -INF);
    q.push(0);

    FOR (i, 1, n) {
        while (!q.empty() && h[q.top()] >= h[i]) {

            int id = q.top();
            q.pop();
            update(1, 0, n, q.top(), id - 1, -b[id]);
        }

        update(1, 0, n, q.top(), i - 1, b[i]);

        f[i] = st[1];

        update_point(1, 0, n, i, f[i]);

        q.push(i);
    }

}

int main() {

    speedup sync

    cin >> n;

    FOR (i, 1, n) cin >> h[i];
    FOR (i, 1, n) cin >> b[i];

    if (n <= 1000) sub1();
    else sub2();

    cout << f[n];

    return 0;
}

