#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI01"

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

ll n, num;

int main() {

    speedup sync

    cin >> n;

    while (n != 0) {
        num += n % 10;
        n /= 10;
    }

    int sr = sqrt(num);

    if (sr * sr == num) cout << num;
    else cout << num % 11;

    return 0;
}

