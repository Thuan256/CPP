#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("SOK.inp");
    ofstream out("SOK.out");

    ll n, t;
    ll Kmax = LLONG_MIN, Amax = LLONG_MIN;
    inp >> n >> t;

    vector<ll> a(n), queries(t), missing;
    set<ll> ap;

    for (ll i = 0; i < n; i++) {
        inp >> a[i];
        ap.insert(a[i]);
    }

    for (ll i = 0; i < t; ++i) {
        inp >> queries[i];
    }

    ll max_k = *max_element(queries.begin(), queries.end());
    ll cur = 1;

    while (missing.size() < max_k) {
        if (ap.find(cur) == ap.end()) {
            missing.push_back(cur);
        }
        cur++;
    }

    for (ll k: queries) {
        out << missing[k - 1] << endl;
    }

    inp.close();
    out.close();

    return 0;
}
