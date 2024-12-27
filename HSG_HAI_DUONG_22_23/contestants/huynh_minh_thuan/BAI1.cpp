#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("BAI1.inp");
    ofstream out("BAI1.out");

    int a, h;
    double alpha;

    inp >> a >> alpha >> h;

    double ans = h + a * tan(alpha * 3.14159265359 / 180.0);

    out << fixed << setprecision(3) << ans;

    inp.close();
    out.close();

    return 0;
}
