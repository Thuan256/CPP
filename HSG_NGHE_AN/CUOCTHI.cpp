#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inp("CUOCTHI.inp");
    ofstream out("CUOCTHI.out");

    int n, q;
    inp >> n >> q;

    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        inp >> x[i];
    }

    sort(x.begin(), x.end());

    for (int i = 0; i < q; i++) {
        int a, b;
        inp >> a >> b;

        if (a > *x.crbegin()) out << 0;
        else {
            int m = lower_bound(x.begin(), x.end(), a + 1) - x.begin();
            int n = lower_bound(x.begin(), x.end(), b + 1) - x.begin();
            cout << m << " " << n << endl;

            out << n - m;
        }

        out << endl;
    }

    inp.close();
    out.close();

    return 0;
}
