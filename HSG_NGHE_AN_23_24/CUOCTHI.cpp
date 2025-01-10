#include <bits/stdc++.h>
<<<<<<< HEAD
=======

>>>>>>> 0da32ed0cc37bffb3b75ed6a832731541e31a52b
using namespace std;

int main() {
    ifstream inp("CUOCTHI.inp");
    ofstream out("CUOCTHI.out");

    int n, q;
    inp >> n >> q;

    vector<int> x(n);

<<<<<<< HEAD
    for (int i = 0; i < n; i++) {
        inp >> x[i];
    }
=======
    for (int i = 0; i < n; i ++) inp >> x[i];
>>>>>>> 0da32ed0cc37bffb3b75ed6a832731541e31a52b

    sort(x.begin(), x.end());

    for (int i = 0; i < q; i++) {
        int a, b;
        inp >> a >> b;

<<<<<<< HEAD
        if (a > *x.crbegin()) out << 0;
        else {
            int m = lower_bound(x.begin(), x.end(), a + 1) - x.begin();
            int n = lower_bound(x.begin(), x.end(), b + 1) - x.begin();
            cout << m << " " << n << endl;

            out << n - m;
        }

        out << endl;
=======
        int m = lower_bound(x.begin(), x.end(), a) - x.begin();
        int n = upper_bound(x.begin(), x.end(), b) - x.begin();

        out << max(0, n - m) << endl;
>>>>>>> 0da32ed0cc37bffb3b75ed6a832731541e31a52b
    }

    inp.close();
    out.close();

    return 0;
}
