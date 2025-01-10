#include <bits/stdc++.h>
using namespace std;

#define NAME "COINLK"

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

int p, s, n;
string str;

void solve() {
    s = n = 0;

    cin >> str;

    for (char c: str) {
        if (c == 'S') s++;
        else n++;
    }

    int x = __gcd(s, n);

    cout << s / x << "/" << n / x << endl;
}

int main() {

    speedup sync

    cin >> p;
    while (p--) solve();

    return 0;
}
