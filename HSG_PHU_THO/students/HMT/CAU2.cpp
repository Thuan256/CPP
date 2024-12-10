#include <bits/stdc++.h>

using namespace std;

int sum(int n) {
    if (n == 0) return 0;

    return n % 10 + sum(n / 10);
}

int main() {
    ifstream inp("CAU2.inp");
    ofstream out("CAU2.out");

    int a, b;
    inp >> a >> b;

    int gcd = __gcd(a, b);
    int ans = 0;

    for (int i = 1; i <= sqrt(gcd); i++) {

        if (gcd % i == 0) {

            ans = max(ans, sum(i));

            if (gcd / i != i) ans = max(ans, sum(gcd / i));
        }
    }

    out << ans;
    out.close();
    inp.close();

    return 0;
}

