#include <bits/stdc++.h>
using namespace std;

vector<bool> eratosthenes(long long n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    for (long long p = 2; p * p <= n; p++) {
        if (primes[p]) {
            for (long long i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    return primes;
}

int main() {
    int T;
    cin >> T;

    vector<long long> a(T);
    for (int i = 0; i < T; i++) {
        cin >> a[i];
    }

    long long maxX = *max_element(a.begin(), a.end());

    long long MAXN = 2e7;
    vector<bool> sieves = eratosthenes(MAXN);

    vector<long long> dp(maxX + 1, 0);
    long long c = 1;

    for (long unsigned int i = 2; i < sieves.size(); i++) {
        if (sieves[i]) {
            dp[c] = dp[c - 1] + i;
            c++;
            if (c > maxX) break;
        }
    }

    for (long long x : a) {
        cout << dp[x] << endl;
    }

    return 0;
}
