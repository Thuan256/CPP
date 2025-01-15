#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI03"

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

int n, a[oo], maxA, ans;

unordered_map<int, bool> mp;

void sub123() {
    FOR (i, 1, n) mp[2 * a[i]] = true;

    FOR (i, 1, n) {
        FOR (j, i + 1, n) {
            int sum = a[i] + a[j];

            ans += mp[sum];
            mp[sum] = false;
        }
    }

    cout << ans;
}

int cnt[5007];
bool chk[5007];

void sub4() {
    FOR (i, 1, n) cnt[a[i]]++;

    FOR (i, 1, maxA) {
        if (cnt[i] > 1) chk[i] = true;

        for (int j = i + 2; j <= maxA; j += 2) {
            chk[(i + j) / 2] = cnt[i] && cnt[j] && cnt[(i + j) / 2];
        }
    }

    FOR (i, 1, maxA) {
        ans += cnt[i] * chk[i];
    }

    cout << ans;
}

int main() {

    speedup sync

    cin >> n;

    FOR (i, 1, n) cin >> a[i], maxA = max(maxA, a[i]);

    if (n <= 3e3 && maxA <= 1e9) {
        sub123();
    } else {
        sub4();
    }
    return 0;
}
