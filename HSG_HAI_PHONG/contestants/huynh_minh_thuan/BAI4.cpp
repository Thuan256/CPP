#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("BAI4.inp");
    ofstream out("BAI4.out");

    int n, q;
    inp >> n >> q;

    for (int _ = 0; _ < q; _++) {
        int u, v;
        inp >> u >> v;

        int a = n - u + 1;
        int b = n - v + 1;

        vector<vector<int>> matrix(a, vector<int>(b, 1));

        for (int i = 1; i <= a - 1; i++) {
            for (int j = 1; j <= b - 1; j++) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
        out << matrix[a - 1][b - 1] << endl;
    }

    inp.close();
    out.close();

    return 0;
}
