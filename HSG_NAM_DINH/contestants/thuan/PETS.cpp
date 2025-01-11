#include <bits/stdc++.h>
using namespace std;

#define NAME "PETS"

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

int n, m, a, b, c;

int main() {

    speedup sync

    cin >> n >> m >> a >> b >> c;

    n = max(n - a, 0);
    m = max(m - b, 0);

    cout << abs(min(c - n - m, 0));

    return 0;
}

