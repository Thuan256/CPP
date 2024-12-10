#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ifstream inp("CAU1.inp");
    ofstream out("CAU1.out");

    ll n, k;
    inp >> n >> k;

    ll ans = 0;

    if (n > k / 2)
        for (ll i = 1; i <= (k + 1) / 2 - 1; i++) if (k - i <= n) ans++;
    out << ans;
    inp.close();
    out.close();
    return 0;
}
