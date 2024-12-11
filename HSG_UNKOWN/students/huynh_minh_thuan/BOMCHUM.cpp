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
    ifstream inp("BOMCHUM.inp");
    ofstream out("BOMCHUM.out");

    int n;
    inp >> n;

    vector<ll> a(n);

    vector<bool> sieves = eratosthenes(10e5);

    for (int i = 0; i < n; i ++) {
        inp >> a[i];

        ll x = a[i], sum = x + (x != 1);

        if (!(x < 10e5 && sieves[x])) {
            for (int dvs = 2; dvs <= sqrt(x); dvs++) {
                if (x % dvs == 0) {
                    ll q = x / dvs;

                    if (q == dvs) sum += dvs;
                    else sum += dvs + q;
                }
            }
        }

        out << sum << " ";

    }

    out.close();
    inp.close();

    return 0;
}
