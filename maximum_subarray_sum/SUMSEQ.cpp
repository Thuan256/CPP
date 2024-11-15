#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    ifstream inp("SUMSEQ.inp");

    getline(inp, line);
    int n = stoi(line);

    getline(inp, line);
    inp.close();

    stringstream ss(line);
    vector<long long> a(n);

    for (int i = 0; i < n; i++) ss >> a[i];

    long long maxSum = a[0], sum = a[0];

    for (int i = 1; i < n; i++) {
        sum = max(sum + a[i], a[i]);

        maxSum = max(sum, maxSum);
    }

    ofstream out("SUMSEQ.out");
    out << maxSum;
    out.close();

    return 0;
}