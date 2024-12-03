#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<bool> eratosthenes(ll n) {
    vector<bool> prime(n+1, true);

    prime[0] = prime[1] = false;

    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    return prime;
}

int main() {

    string T;
    cin >> T;
    int a = T.length();

    ll max_prime = -1;

    vector<bool> sieves = eratosthenes(1e8);

    for (int i = 0; i < a; i++) {

        ll tmp = 0;

        for (int j = i; j < a; j++) {

            if (T[j] < '0' || T[j] > '9') break;

            tmp = tmp * 10 + (T[j] - '0');

            if (tmp >= 1e8) break;

            if (sieves[tmp]) max_prime = max(max_prime, tmp);
        }
    }

    cout << max_prime;

    return 0;
}
