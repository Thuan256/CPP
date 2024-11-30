#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int fac(int n) {
    if (n < 2) return 1;
    return n * fac(n - 1);
}

int main() {

    ifstream inp("BAI4.inp");
    string line;
    getline(inp, line);

    short t = stoi(line);
}
