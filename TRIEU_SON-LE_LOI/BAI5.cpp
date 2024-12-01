#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("BAI5.inp");
    string line;
    getline(inp, line);

    int n = stoi(line);
    long long a[n];

    getline(inp, line);
    stringstream ss(line);
    int s = 0;
    for (int i = 0; i < n; i++) {
        ss >> a[i];
        s += (i % 2 == 0) ? -a[i] : +a[i];
    }

    cout << s;
}