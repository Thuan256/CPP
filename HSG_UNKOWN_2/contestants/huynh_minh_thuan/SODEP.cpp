#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ifstream inp("SODEP.inp");
    ofstream out("SODEP.out");

    ll n, ans = 0;
    inp >> n;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int d = n / i;

            if (d == i) ans++;
            else ans += 2;
        }
    }

    out << ans;

    inp.close();
    out.close();

    return 0;
}
