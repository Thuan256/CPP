#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inp("CAU3.inp");
    ofstream out("CAU3.out");

    string s;
    inp >> s;

    map<char, int> app;
    long long ans = 1;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (app[c]) {
             app.clear();
             ans++;
        }

        app[c]++;
    }

    out << ans;
    inp.close();
    out.close();

    return 0;
}
