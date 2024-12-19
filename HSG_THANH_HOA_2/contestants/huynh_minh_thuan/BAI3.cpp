#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("BAI3.inp");
    ofstream out("BAI3.out");

    int n, k;
    inp >> n >> k;

    ll a[n], ans = 0;
    vector<vector<ll>> ranges(k);

    for (int i = 0; i < n; i++) {
        inp >> a[i];
        ranges[i % k].push_back(a[i]);
    }

    for (auto range: ranges) {
        sort(range.begin(), range.end());

        ll mid = range[range.size() / 2];

        for (ll val: range) {
            ans += abs(val - mid);
        }
    }

    out << ans;

    inp.close();
    out.close();

    return 0;
}
