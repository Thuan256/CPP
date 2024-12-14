#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("BAI2.inp");
    ofstream out("BAI2.out");

    ll n, k, sum = 0, ans = 0;
    inp >> n >> k;
    ll a[n];

    for (int i = 0; i < n; i++) inp >> a[i];
    inp.close();

    int i = 0, j = 0;

    while (j < n) {
        sum += a[j];

        while (sum >= k && i < n) {
            ans = max(ans, sum / (j - i + 1));
            sum -= a[i];
            i++;

        }
        j++;
    }

    if (ans) out << ans;
    else out << "NO";

    out.close();
    return 0;
}
