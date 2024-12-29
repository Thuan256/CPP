#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("DIVISION.INP");
    ofstream out("DIVISION.OUT");

    int n;

    inp >> n;

    while (n--) {
        long long x, l;
        string s;
        inp >> x >> l >> s;

        int k = 0;

        for (int i = 0; i <= s.size() - l; i++) {
            long long so = stoll(s.substr(i, l));

            if (to_string(so).size() == l) {
                if (so % x == 0) k++;
            }
        }
        out << k << endl;
    }
    out.close();
    return 0;
}
