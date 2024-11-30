#include <iostream>
#include <fstream>
using namespace std;

int fibo(int n) {
    if (n <= 1)
        return n;

    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    ifstream inp("fibo.inp");
    string line;

    getline(inp, line);

    int m = stoi(line);

    ofstream out("fibo.out");
    out << fibo(m);
    out.close();

    return 0;
}
