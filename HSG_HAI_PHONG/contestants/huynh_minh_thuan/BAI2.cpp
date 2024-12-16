#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("BAI2.inp");
    ofstream out("BAI2.out");

    ll n, k, sum = 0, ans = LLONG_MIN;
    inp >> n >> k;
    ll a[n];

    for (int i = 0; i < n; i++) inp >> a[i];
    inp.close();

    int i = 0, j = -1;

    while (++j < n) {
        if (a[j] < 0) {
            sum = 0;
            i = j;

            if (a[j] >= k) ans = max(ans, a[j]);
        } else {
            sum += a[j];

            while (sum >= k && i < n) {
                ans = max(ans, sum / (j - i + 1));
                sum -= a[i];
                i++;
            }
        }
    }

    if (ans != LLONG_MIN) out << ans;
    else out << "NO";

    out.close();
    return 0;
}
