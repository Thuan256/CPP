#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {

    ifstream inp("BAI2.inp");
    string line;
    getline(inp, line);

    int n, k, range = 0;
    stringstream ss(line);

    ss >> n;
    ss >> k;

    int a[n];
    int changes[k];

    getline(inp, line);
    for (int i = 0; i < n; i++) {

        a[i] = line[i] - '0';

        if (i) range += (a[i] == a[i - 1]) + 1;
    }

    getline(inp, line);
    inp.close();
    stringstream ss_changes(line);
    ofstream out("BAI2.out");

    for (int i = 0; i < k; i++) {
        int j;
        ss_changes >> j;
        j--;

        a[j] = !a[j];

        if (j) range += a[j] == a[j-1] ? 1 : -1;
        if (n - 1 - j) range += a[j] == a[j+1] ? 1 : -1;

        out << range << endl;
    }
    out.close();
    return 0;
}
