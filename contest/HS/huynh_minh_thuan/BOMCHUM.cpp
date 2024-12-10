#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<bool> eratosthenes(int n) {
    vector<bool> primes(n + 1, true);

    primes[0] = primes[1] = false;

    for (int p = 2; p * p <= n; p++)
        if (primes[p])
            for (int i = p * p; i <= n; i += p)
                primes[p] = false;

    return primes;
}

int main() {
    ifstream inp("BOMCHUM.inp");
    ofstream out("BOMCHUM.out");

    int n;
    inp >> n;

    vector<ll> a(n);

    vector<bool> sieves = eratosthenes(10e5);

    for (int i = 0; i < n; i ++) {
        inp >> a[i];

        ll x = a[i], sum = 1;

        for (int p = 2; i < sieves.size(); p++) {
            if (sieves[p]) {
                if (p * p > x) break;

                if (x % p == 0) {
                    ll power_sum = 1, pow = 1;

                    while (x % p == 0) {
                        x /= p;
                        pow *= p;
                        power_sum += pow;
                    }

                    sum *= power_sum;
                }
            }
        }

        if (x > 1) sum *= (x + 1);
        out << sum << " ";

    }

    out.close();
    inp.close();

    return 0;
}
