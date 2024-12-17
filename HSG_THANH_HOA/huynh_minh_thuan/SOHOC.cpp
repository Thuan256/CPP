#include <bits/stdc++.h>
#define ll long long

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
    ifstream inp("SOHOC.inp");
    ofstream out("SOHOC.out");

    ll n, i = 2, divisors = 2, max_prime = 2;
    inp >> n;

    vector<bool> sieves = eratosthenes(2e7);

    for (; i <= sqrt(n); i++) {
        if (n % i == 0) {

            if (sieves[i]) max_prime = max(max_prime, i);

            ll d = n / i;

            if (d != i) {
                divisors += 2;
                if (d < 2e7 && sieves[d]) max_prime = max(max_prime, d);
            } else divisors++;
        }
    }

    if (divisors == 2) max_prime = n;

    out << divisors << endl << max_prime;
    inp.close();
    out.close();

    return 0;
}
