#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("BAI3.inp");
    ofstream out("BAI3.out");

    int n, m;
    inp >> n >> m;

    vector<ll> a(n);
    ll ans = 0;

    for (int i = 0; i < n; i++) inp >> a[i];

    while (m--) {

        int last = a.size() - 1;

        if (a[0] > a[last]) {
            ans += a[0];
            a.erase(a.begin());
        } else {
            ans += a[last];
            a.pop_back();
        }
    }

    out << ans;

    inp.close();
    out.close();

    return 0;
}
