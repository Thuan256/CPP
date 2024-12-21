#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("BAI5.inp");
    ofstream out("BAI5.out");

    int n;
    inp >> n;
    vector<int> a(n);

    long long ans = 0;

    for (int i = 0; i < n; i++) inp >> a[i];

    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            ans += a[i];
        else
            ans += max(0, a[i] - a[i + 1]);
    }
    out << ans;

    inp.close();
    out.close();

    return 0;
}
