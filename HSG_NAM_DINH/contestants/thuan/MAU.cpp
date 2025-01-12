#include <bits/stdc++.h>
using namespace std;

#define NAME "MAU"

#define oo 10000007
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, m, a[oo], L = 1, R = 1, ans = INT_MAX;
unordered_map<int, int> mp;

int main() {

    speedup sync

    cin >> n >> m;

    FOR (i, 1, n) cin >> a[i];

    while (R < n) {
        mp[a[R]]++;

        while (mp.size() == m) {
            ans = min(ans, R - L + 1);

            mp[a[L]]--;

            if (!mp[a[L]]) mp.erase(a[L]);
            L++;
        }
        R++;
    }

    cout << ans;

    return 0;
}

