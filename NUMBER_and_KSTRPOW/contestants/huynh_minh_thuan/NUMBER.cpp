#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("NUMBER.inp");
    ofstream out("NUMBER.out");

    int n, k;
    inp >> n >> k;

    vector<ll> a(n);
    map<int, int> r;
    ll ans = 0;

    for (size_t i = 0; i < n; i++) {
        inp >> a[i];
        r[a[i] % k]++;
    }

    ans += min(1, r[0]);

    for (int i = 1; i <= k / 2; i++) {

        if (i == k - i) {
            ans += min(1, r[i]);
        } else {
            ans += max(r[i], r[k - i]);
        }
    }

    out << ans;

    return 0;
}
