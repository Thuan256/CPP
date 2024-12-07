#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("CUOCTHI.inp");
    ofstream out("CUOCTHI.out");

    int n, q;
    inp >> n >> q;

    vector<int> x(n);

    for (int i = 0; i < n; i ++) inp >> x[i];

    sort(x.begin(), x.end());

    for (int i = 0; i < q; i++) {
        int a, b;
        inp >> a >> b;

        int m = lower_bound(x.begin(), x.end(), a) - x.begin();
        int n = upper_bound(x.begin(), x.end(), b) - x.begin();

        out << max(0, n - m) << endl;
    }

    inp.close();
    out.close();

    return 0;
}
