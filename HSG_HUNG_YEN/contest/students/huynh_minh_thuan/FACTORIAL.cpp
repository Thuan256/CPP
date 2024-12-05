#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 20240131;
const ll cycle = mod - 1;

int main() {
    ifstream inp("FACTORIAL.inp");
    ofstream out("FACTORIAL.out");

    ll n;
    inp >> n;

    vector<ll> fac_mod(cycle + 1);
    fac_mod[0] = 1;
    ll sum_cycle = 0;

    for (ll i = 1; i <= cycle; ++i) {
        fac_mod[i] = (fac_mod[i - 1] * i) % mod;
        sum_cycle += (sum_cycle + fac_mod[i]) % mod;
    }

    ll full_cycles = n / cycle;
    ll ans = 0;

    while (full_cycles--) {
        ans = (ans + sum_cycle) % mod;
    }
    ll last_cycle = n % cycle;

    for (ll i = 1; i <= last_cycle; i++) {
        ans = (ans + fac_mod[i]) % mod;
    }

    out << ans;

    out.close();
    inp.close();
    return 0;
}
