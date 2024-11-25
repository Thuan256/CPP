#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<bool> eratosthenes(int n) {
    vector<bool> sieves(n + 1, true);

    sieves[0] = sieves[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (sieves[p]) {
            for (int i = p * p; i <= n; i += p) {
                sieves[i] = false;
            }
        }
    }

    return sieves;
}

int sum_num(int x) {
    int sum = 0;

    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ifstream inp("TNT.INP");
    string line;
    getline(inp, line);
    inp.close();

    stringstream ss(line);

    int a, b;
    ss >> a;
    ss >> b;

    int c = 0;

    vector<bool> primes = eratosthenes(72);

    for (int i = a; i <= b; i++) {
        c += primes[sum_num(i)];
    }

    ofstream out("TNT.OUT");
    out << c;
    out.close();

    return 0;
}
