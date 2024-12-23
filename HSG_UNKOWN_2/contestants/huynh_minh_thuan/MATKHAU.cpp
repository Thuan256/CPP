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

int sum_digits(int n) {

    int sum = 0;

    while (n != 0) {
        sum += (n % 10);
        n /= 10;
    }

    return sum;
}

int main() {
    ifstream inp("MATKHAU.inp");
    ofstream out("MATKHAU.out");

    int L, R;
    inp >> L >> R;

    vector<bool> sieves = eratosthenes(2e7);

    for (int i = L; i <= R; i++) {
        if (sieves[i] && sieves[sum_digits(i)]) out << i << " ";
    }

    inp.close();
    out.close();

    return 0;
}
