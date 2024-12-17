#include <bits/stdc++.h>
const int mod = 1e9 + 7;

using namespace std;

int main() {
    ifstream inp("BAI4.inp");
    ofstream out("BAI4.out");

    int n, q, i, j;
    static int ans[1001][1001];
    inp >> n >> q;

    ans[0][1] = 1;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            ans[i][j] = (ans[i - 1][j] % mod + ans[i][j - 1] % mod) % mod;


    for (i = 0; i < q; i++) {
        int u, v;
        inp >> u >> v;

        int a = n - u + 1;
        int b = n - v + 1;

        out << ans[a][b] << endl;
    }

    inp.close();
    out.close();

    return 0;
}
