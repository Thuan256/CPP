#include <bits/stdc++.h>
using namespace std;

#define NAME "SOCHAN"

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

int n, r, ans;

int sum(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }

    return res;
}

int main() {

    speedup sync

    cin >> n;


    if (n % 10 > 0) {

        r = ceil(1.0 * (n % 10) / 2) + (sum(n / 10) % 2 == 0 && sum(n) % 2 == 0);
    }

    ans = n / 10 * 5 - 1 + r;

    cout << ans;

    return 0;
}

