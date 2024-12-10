#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("NHATKY.inp");
    ofstream out("NHATKY.out");

    string str;
    getline(inp, str);

    int n = stoi(str), s;

    getline(inp, str);
    inp >> s;

    inp.close();

    map<int, bool> mp;

    int i = 0, ans = 0;

    while (i < str.size()) {

        int num = 0;

        if (isdigit(str[i])) {
            int sign = i > 0 && str[i - 1] == '-' ? -1 : 1;

            while (isdigit(str[i])) {
                num = num * 10 + str[i] - '0';
                i++;
            }

            num *= sign;

            if (mp[num]) ans++;
            mp[s - num] = true;

        } else i++;
    }

    out << ans;
    out.close();

    return 0;
}
