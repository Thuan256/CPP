#include <bits/stdc++.h>
using namespace std;

#define NAME "DIVISION"

#define limit 1000007
#define ll long long
#define ull unsigned long long
#define FOD(i,b,a) for (int i = (int) b; i >= (int) a; i--)
#define FOR(i,a,b) for (int i = (int) a; i <= (int) b; i++)
#define speedup ios_base::sync_with_stdio(0); cin.tie(0);
#define sync freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout);

int x, l, T;
string s;


bool isDivisible(const string &a, int b) {
    long long remainder = 0;
    for (char digit : a) {
        remainder = (remainder * 10 + (digit - '0')) % b;
    }
    return remainder == 0;
}


void solve() {
    ll ans = 0;
    ll num = 0;

    cin >> x >> l >> s;

    string sub = "";

    int i = 0, j = 0;

    while (j < s.size()) {

        sub.push_back(s[j]);

        if (j - i + 1 == l ) {
            if (sub[0] != '0' && isDivisible(sub, x)) ans++;

            sub.erase(0, 1);
            i++;
        }
        j++;
    }

    cout << ans << endl;
}

int main() {

    speedup sync

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
