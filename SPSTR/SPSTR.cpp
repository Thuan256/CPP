#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("SPSTR.inp");

    string str;
    getline(inp, str);

    inp.close();

    string prefix = "";

    int i = 0, c = 0;

    while (str.length() > prefix.length()) {
        prefix.push_back(str[i++]);

        if (str == prefix) {
            prefix = "None ";
            break;
        }

        if (!str.compare(str.length() - prefix.length(), prefix.length(),
                         prefix)) {
            string mid_range =
                str.substr(prefix.length(), str.length() - 2 * prefix.length());

            if (mid_range.find(prefix) == string::npos) {
                prefix = "None ";
                break;
            } else {
                if ((str.length() % 2) == (prefix.length() % 2)) {
                    string mid = str.substr(
                        (str.length() - prefix.length()) / 2, prefix.length());

                    c += (c == 0);
                }
            }

        } else {
            if (c) break;
        }
    }

    prefix.pop_back();

    cout << prefix;
}
