#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ifstream inp("BONUS.inp");

    string line;
    getline(inp, line);

    short n, k;
    stringstream ss1(line);
    ss1 >> n;
    ss1 >> k;

    vector<vector<int>> a(n, vector<int>(n));

    short i = 0;

    while (i < n) {
        short j = 0, num;
        getline(inp, line);

        stringstream ss2(line);
        while (j < n) ss2 >> a[i][j++];
        i++;
    }

    vector<vector<int>> x(a[0].begin(), a[0].begin() + 2);

    for (short i = 0; i < x.size(); i++) {
        // for (short j = 0; j < n; j++) {
        //     cout << a[i][j] << " ";
        // }

        cout << x[0][i] << " ";
    }      
}
