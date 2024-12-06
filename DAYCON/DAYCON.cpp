#include <bits/stdc++.h>

using namespace std;

vector<bool> eratosthenes(int n) {

    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (primes[p]) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    return primes;
}

int main() {
    ifstream inp("DAYCON.inp");
    ofstream out("DAYCON.out");

    int n;
    inp >> n;
    int a[n];

    int ans = -1, last = -1;

    vector<bool> sieves = eratosthenes(2e7);

    for (int i = 0; i < n; i++) {
        inp >> a[i];

        if (sieves[a[i]]) {
            if (last != -1) {

                int len = i - last + 1;

                ans = (ans == -1) ? len : min(len, ans);
            }
            last = i;
        }
    }

    out << ans;
    inp.close();
    out.close();

    return 0;

}
