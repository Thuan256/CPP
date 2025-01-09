#include <bits/stdc++.h>
using namespace std;

#define NAME "COMPUTER"

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

int a[4], b[4], A, B, C, ans;

void connect(int& a, int& b) {
    ans += min(a, b);
    a = max(a - b, 0);
    b = max(b - a, 0);
}

int main() {

    speedup sync

    FOR (i, 1, 3) cin >> a[i];
    FOR (i, 1, 3) cin >> b[i];

    connect(a[1], b[1]);
    connect(a[2], b[2]);

    FOR (i, 1, 3) connect(a[3], b[i]);
    FOR (i, 1, 3) connect(b[3], a[i]);

    cout << ans;

    return 0;
}
