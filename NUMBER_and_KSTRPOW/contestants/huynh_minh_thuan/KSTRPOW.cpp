#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("KSTRPOW.inp");
    ofstream out("KSTRPOW.out");

    string s, t;
    int k;

    inp >> s >> t >> k;

    string str = s;

    for (int i = 1; i < k; i++) str += s;

    if (str == t) out << "YES";
    else out << "NO";

    return 0;
}
