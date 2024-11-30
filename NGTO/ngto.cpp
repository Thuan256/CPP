#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    ifstream inp("ngto.inp");
    string line;

    getline(inp, line);

    stringstream ss_n(line);
    int n, num, a[n], c;

    ss_n >> n;

    getline(inp, line);
    inp.close();
    stringstream ss(line);

    for (int i = 0; i < n; i++ ) ss >> a[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) c += (__gcd(a[i], a[j]) == 1);

    ofstream out("ngto.out");
    out << c;
    out.close();
    return 0;
}
