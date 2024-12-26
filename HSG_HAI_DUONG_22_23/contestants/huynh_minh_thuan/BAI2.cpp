#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("BAI2.inp");
    ofstream out("BAI2.out");

    int n, i = 0;
    long long c = 0, ans = 0;
    string res;

    inp >> n >> res;

    while (i < n) {
        if (res[i] == '0') i++;
        else while (res[i] == '1') c++, i++;

        ans += c * (c + 1) / 2;
        c = 0;
    }

    out << ans;

    inp.close();
    out.close();

    return 0;
}
