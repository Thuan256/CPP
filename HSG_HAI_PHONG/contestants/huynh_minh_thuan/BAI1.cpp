#include <bits/stdc++.h>

using namespace std;

vector<bool> eratosthenes(int n) {
    vector<bool> primes(n + 1, true);

    primes[0] = primes[1] = false;

    for (int p = 2; p * p <= n; p++)
        if (primes[p])
            for (int i = p * p; i <= n; i += p)
                primes[i] = false;


    return primes;
}

int main() {
    ifstream inp("BAI1.inp");
    ofstream out("BAI1.out");

    int a, b, ans = 0, MAXN = 32767;
    inp >> a >> b;
    inp.close();

    vector<bool> sieves = eratosthenes(MAXN);

    for (int i = 2; i < MAXN; i++) {
        if (sieves[i]) {
            int x = i * i;

            ans += (a <= x && x <= b);
        }
    }

    out << ans;
    out.close();
    return 0;

}
