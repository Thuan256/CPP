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

    int a, b;
    ss >> a;
    ss >> b;

    for (int i = a; i <=b; i++) {
        if (sum_num(i) % )
    }
}