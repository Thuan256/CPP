#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int sum_num(int x) {
    int sum;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ifstream inp("CHIAHET.INP");
    string line;

    getline(inp, line);
    inp.close();

    stringstream ss(line);

    int a, b, k, count = 0;
    ss >> a;
    ss >> b;
    ss >> k;

    for (int i = a; i <= b; i++) count += (sum_num(i) % k == 0 && i % k == 0);

    ofstream out("CHIAHET.OUT");
    out << count;
    out.close();

    return 0;
}
