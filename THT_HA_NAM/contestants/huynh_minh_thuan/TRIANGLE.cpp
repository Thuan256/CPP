#include <bits/stdc++.h>
using namespace std;

#define NAME "TRIANGLE"

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

int n, ans, num;
char clr;
multiset<int> r, b, g;

bool valid (int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
}

int main() {

    speedup sync

    cin >> n;

    FOR (i, 1, n) {
        cin >> clr >> num;

        if (clr == 'r') r.insert(num);
        else if (clr == 'b') b.insert(num);
        else g.insert(num);
    }

    for (int a: r)
        for (int b: b)
            for (int c: g)
                ans += valid(a, b, c);



    cout << ans;

    return 0;
}
