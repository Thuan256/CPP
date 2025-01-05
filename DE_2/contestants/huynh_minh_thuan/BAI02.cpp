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

bool isStair(int n) {

    while (n != 0) {
        int num = n % 10;
        n /= 10;
        if (num <= n % 10) return false;
    }

    return true;
}

int n, num, ans;

int main() {

    speedup sync

    cin >> n;

    vector<bool> sie = eratos(2e6);

    FOR (i, 1, n) {
        cin >> num;
        ans += (num > 10 && sie[num] && isStair(num));
    }

    cout << ans;

    return 0;
}

