#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("BALANCE.inp");
    ofstream out("BALANCE.out");

    string line;
    getline(inp, line);

    ll n = stoi(line);
    ll a[n];

    getline(inp, line);
    inp.close();

    stringstream ss(line);

    pair<ll,ll> sum(0, 0);
    ll min_diff = INT_MAX;

    for (ll i = 0; i < n; i++) {
        ss >> a[i];
        sum.second += a[i];
    }

    for (ll i = 0; i < n; i++) {

        sum.first += a[i];
        sum.second -= a[i];

        min_diff = min(min_diff, abs(sum.first - sum.second));
    }

    out << min_diff;
    out.close();
    return 0;
}
