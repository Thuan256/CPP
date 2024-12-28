#include <bits/stdc++.h>
using namespace std;

#define fmax 1000007
#define NAME ""
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long


int main() {
    ifstream inp("BAI3.inp");
    ofstream out("BAI3.out");

    int n, m;
    inp >> n >> m;

    int a[n + 1];
    ll ps[n + 1];

    ps[0] = 0;

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        inp >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }

    for (int L = 0; L <= m; L++) {
        ans = max(ans, ps[L] + (ps[n] - ps[n - (m - L)]));
    }

    out << ans;

    inp.close();
    out.close();

    return 0;
}

