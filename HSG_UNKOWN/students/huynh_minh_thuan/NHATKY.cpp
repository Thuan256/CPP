#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ifstream inp("NHATKY.inp");
    ofstream out("NHATKY.out");

    string str;
    getline(inp, str);

    ll n = stoi(str), s;

    getline(inp, str);
    inp >> s;

    inp.close();

    map<ll, ll> mp;

    ll i = 0, ans = 0;

    while (i < str.size()) {

        ll num = 0;

        if (isdigit(str[i])) {
            int sign = i > 0 && str[i - 1] == '-' ? -1 : 1;

            while (isdigit(str[i])) {
                num = num * 10 + str[i] - '0';
                i++;
            }

            num *= sign;

            ans += mp[num];
            mp[s - num]++;

        } else i++;
    }

    out << ans;
    out.close();

    return 0;
}
