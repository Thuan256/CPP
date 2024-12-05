#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 20240131;

int main() {
    ifstream inp("FACTORIAL.inp");
    ofstream out("FACTORIAL.out");

    string line;
    getline(inp, line);
    int n = stoi(line);

    ll ans = 0;
    ll fac = 1;

    for (ll i = 1; i <= n; i++) {
        fac *= i;
        ans += (fac % mod);
    }

    out << ans;
    out.close();
    inp.close();
    return 0;
}
