#include <bits/stdc++.h>
using namespace std;

#define NAME "BSET"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, m, num, ans = 0;
unordered_map<int, bool> a, c;

int main() {

    speedup sync

    cin >> n >> m;

    FOR (i, 1, n) {
        cin >> num;
        a[num] = true;
        c[num] = true;
    }

    FOR (i, 1, m) {
        cin >> num;
        if (a[num]) {
            ans++;
            a[num] = false;
        }
        c[num] = true;
    }

    cout << c.size() << " " << ans;

    return 0;
}

