#include <bits/stdc++.h>
using namespace std;

#define NAME "SONGAY"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int m, y;

int main() {

    speedup sync

    cin >> m >> y;

    bool isLeapYear = (y % 4 == 0) && (y % 100 != 0);
    bool even = (m % 2 == 0);

    if (m == 2) cout << 28 + isLeapYear;
    else if (m < 8) cout << 30 + !even;
    else cout << 30 + even;

    return 0;
}

