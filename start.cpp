#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string s,t,ss = "";
    ll k;

    cin >> s >> t >> k;

    for (ll i = 0; i < k; i++) ss += s;

    unsigned long int c = 0;
    string::size_type pos = 0;

    for (;;) {
        pos = ss.find(t, pos);
        if (pos == string::npos) break;
        ss.erase(0, 1);
        c++;
    }
    cout << c;

    return 0;
}
