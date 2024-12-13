#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inp("NAUAN.inp");
    ofstream out("NAUAN.out");

    int n, m, a, p, t = 0;
    map<int, int> mp;

    inp >> n;

    for (int i = 1; i <= n; i++) {
        inp >> a;

        for (int k = t + 1; k <= t + a; k++) mp[k] = i;
        t += a;
    }

    inp >> m;

    for (int i = 0; i < m; i++) {
        inp >> p;
        out << mp[p] << " ";
    }

    inp.close();
    out.close();

    return 0;
}
