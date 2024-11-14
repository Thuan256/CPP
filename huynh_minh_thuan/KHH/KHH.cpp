#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

bool isPerfectNum(int n) {
    int sum = 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += (n / i);
            }
        }
    }

    return (sum > n);
}

int main() {
    ifstream inp("KHH.inp");
    string line;

    getline(inp, line);
    inp.close();

    stringstream ss(line);

    int a, b;
    ss >> a;
    ss >> b;

    int c = 0;

    int i = a - 1;

    while (++i <= b) c += isPerfectNum(i);

    ofstream out("KHH.OUT");
    out << c;
    out.close();

    return 0;
}