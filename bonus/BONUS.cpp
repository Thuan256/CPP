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

    vector<vector<int>> a(n, vector<int>(n, 0));
    int max_sum = INT32_MIN;

    for (short i = 0; i < n; i++) {
        getline(inp, line);
        stringstream ss2(line);

        for (short j = 0; j < n; j++) {
            ss2 >> a[i][j];

            if (i > 0) a[i][j] += a[i - 1][j];
            if (j > 0) a[i][j] += a[i][j - 1];
            if (i > 0 && j > 0) a[i][j] -= a[i - 1][j - 1];
        }
    }

    for (const vector<int> vec : a) {
        for (int x : vec) {
            cout << x << " ";
        }

        cout << endl;
    }

    for (int i = k - 1; i < n; i++) {
        for (int j = k - 1; j < n; j++) {
            int submatrix_sum = a[i][j];
            if (i >= k) submatrix_sum -= a[i - k][j];
            if (j >= k) submatrix_sum -= a[i][j - k];
            if (i >= k && j >= k) submatrix_sum += a[i - k][j - k];

            max_sum = max(submatrix_sum, max_sum);
        }
    }

    ofstream out("BONUS.out");
    out << max_sum;
    out.close();
    return 0;
}
