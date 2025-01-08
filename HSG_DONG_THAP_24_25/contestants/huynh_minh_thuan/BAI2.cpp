#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI2"

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

int n, a[oo], num;
double nums[oo];
vector<double> c;

int main() {

    speedup sync

    cin >> n;

    FOR (i, 1, n) cin >> a[i];
    FOR (i, 1, n) cin >> num, nums[i] = 1.0 * a[i] / num;

    c.pb(nums[1]);

    FOR (i, 2, n) {

        if (c.back() < nums[i]) {
            c.pb(nums[i]);
        } else {
            int low = lower_bound(c.begin(), c.end(), nums[i]) - c.begin();
            c[low] = nums[i];
        }
    }

    cout << c.size();

    return 0;
}
