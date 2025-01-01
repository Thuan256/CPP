#include <bits/stdc++.h>
using namespace std;

#define NAME "CELE"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int n, num;
vector<int> a(limit);
multiset<int, greater<int>> st;
ll ans = 0;

int main() {

    speedup sync

    cin >> n >> a[1];

    FOR (i, 2, n) {
        cin >> a[i];
        ans +=  a[i] + a[i - 1];
    };

//    for (int num: st) {
//        int i = find(a.begin(), a.end(), num) - a.begin();
//
//        ans += a[i - 1] + a[i] + a[i + 1];
//
//        a.erase(a.begin() + i);
//    }

    cout << ans;

    return 0;
}

