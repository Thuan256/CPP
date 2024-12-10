#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("BOMCHUM.inp");
    ofstream out("BOMCHUM.out");

    int n;
    inp >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i ++) {
        inp >> a[i];
        ll sum = 0;
        for (int j = 1; j <= sqrt(a[i]); j++) {
            if (a[i] % j == 0) {

                ll num = a[i] / j;

                if (num == j)
                    sum += j;
                else
                    sum += j + num;
            }
        }

        out << sum << " ";
    }

    out.close();
    inp.close();

    return 0;
}
