#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("SOK.inp");
    ofstream out("SOK.out");

    ll n, t;
    inp >> n >> t;

    vector<ll> a(n), queries(t), missing;
    set<ll> ap;

    for (ll i = 0; i < n; i++) {
        inp >> a[i];
        ap.insert(a[i]);
    }

    ll max_k = LLONG_MIN;

    for (ll i = 0; i < t; i++) {
        inp >> queries[i];
        max_k = max(queries[i], max_k);
    }

    ll max_ap = *ap.crbegin();
    ll tmp = ceil((max_ap * 2 + 1) / 2);

    max_k = min(tmp, max_k);

    cout << max_k;

    ll cur = 1;

    while (missing.size() < max_k) {
        if (ap.find(cur) == ap.end()) {
            missing.push_back(cur);
        }
        cur++;
    }

    for (ll k: queries) {

        out << missing[min(max_k, k) - 1] << endl;
    }

    inp.close();
    out.close();

    return 0;
}
