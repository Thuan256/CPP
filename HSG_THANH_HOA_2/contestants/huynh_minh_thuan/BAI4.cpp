#include <bits/stdc++.h>

using namespace std;

string solve(map<int, int> mp, int k) {
    for (auto p: mp) {
        int val = p.first;
        int c = p.second;

        if (val >= k) return "YES";

        mp[val + 1] += c / (val + 1);

        if (c % (val + 1)) return "NO";
    }

    return "YES";
}

int main() {
    ifstream inp("BAI4.inp");
    ofstream out("BAI4.out");

    int t;
    inp >> t;

    while (t--) {
        int n, k, num;
        inp >> n >> k;

        map<int, int> mp;

        while (n--) {
            inp >> num;
            if (num < k) mp[num]++;
        }

        out << solve(mp, k) << endl;
    }

    inp.close();
    out.close();

    return 0;

}
