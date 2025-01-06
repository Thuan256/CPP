#include <bits/stdc++.h>
using namespace std;

#define NAME "SUMN"

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

string n;
ll ans;

int main() {

    speedup sync

    cin >> n;

    for (char c: n) {
        ans += (c - '0');
    }

    cout << ans;

    return 0;
}

