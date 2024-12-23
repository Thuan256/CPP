#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inp("DAYCON.inp");
    ofstream out("DAYCON.out");

    int n, m, left = 0, right = 0;
    long long sum = 0, ans = 0;

    inp >> n >> m;

    int a[n];

    for (int i = 0; i < n; i++) inp >> a[i];

    while (right < n) {

        sum += a[right];

        while (sum > m && left <= right) {
            sum -= a[left];
            left++;
        }

        ans += (right - left + 1);
        right++;
    }

    out << ans;

    inp.close();
    out.close();

    return 0;
}
