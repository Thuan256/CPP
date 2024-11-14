#include <iostream>
#include <vector>
using namespace std;

vector<bool> eratosthenes(int n) {

    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {

        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    return prime;
}

int main() {
    int n;

    cout << "Input n = ";
    cin >> n;

    vector<bool> sieve = eratosthenes(n);

    cout << (sieve[n] ? "Yes" : "No");

    return 0;
}
