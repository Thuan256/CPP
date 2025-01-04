#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI02"

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

vector<bool> eratos(int n) {
    vector<bool> pri(n + 1, true);
    pri[0] = pri[1] = false;

    for (int p = 2; p * p <= n; p++)
        if (pri[p])
            for (int i = p * p; i <= n; i += p)
                pri[i] = false;

    return pri;
}

int a, b, ans;

int reverse_num(int x) {
    int num = 0;

    while (x != 0) {
        num = num * 10 + x % 10;
        x /= 10;
    }

    return num;
}

int main() {

    speedup sync

    cin >> a >> b;

    vector<bool> pri = eratos(1e7);

    FOR (i, a, b) {
        int r = reverse_num(i);
        ans += (pri[i] && pri[r]);
    }

    cout << ans;

    return 0;
}

