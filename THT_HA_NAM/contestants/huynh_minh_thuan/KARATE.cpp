#include <bits/stdc++.h>
using namespace std;

#define NAME "KARATE"

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

int n, p, g;
vector<int> a[2];

int main() {

    speedup sync

    cin >> n;

    while (n--) {
        cin >> p >> g;

        int ans = 0;

        if (!a[g].size()) {
            ans = 0;
        } else {
            int j = a[g].size() - 1, ans = 0;
            while (a[g][j] < p && j >= 0) {
                ans++;
                j--;
            }
        }
        a[g].pb(p);

        cout << ans << " ";
    }

    return 0;
}
