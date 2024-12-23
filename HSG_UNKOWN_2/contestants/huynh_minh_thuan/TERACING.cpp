#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("TERACING.inp");
    ofstream out("TERACING.out");

    int n, k, ans = 0, num;
    inp >> n >> k;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        inp >> num;

        ans += mp[num];

        mp[num + k]++;
        mp[num - k]++;
    }

    out << ans;

    inp.close();
    out.close();

    return 0;
}
