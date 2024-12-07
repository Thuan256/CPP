#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("CAU3.inp");
    ofstream out("CAU3.out");

    ll n, H;
    inp >> n >> H;

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++) {
        ll a,b;
        inp >> a >> b;

        vec.push_back({a, b});
    }

    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });

    for (pair<int, int> p: vec) {
        if (H > p.first) {
            H += p.second;
        } else break;
    }

    out << H;
    inp.close();
    out.close();

    return 0;
}
