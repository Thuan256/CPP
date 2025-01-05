#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI03"

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

ll d, n, a[limit], ans, ps;
unordered_map<int, int> mp;

int main() {

    speedup sync

    cin >> d >> n;
    mp[0] = 1;

    FOR (i, 1, n) {
        cin >> a[i];
        ps += a[i];

        int r = ps % d;

        ans += mp[r];

        mp[r]++;
    }
    cout << ans;

    return 0;
}

