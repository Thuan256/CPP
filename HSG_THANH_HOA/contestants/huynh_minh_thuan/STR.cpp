#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ifstream inp("STR.inp");
    ofstream out("STR.out");

    string str;
    inp >> str;

    int n = str.length(), i = -1;
    ll max_num = 0;
    unordered_set<char> chr;

    while (++i < n) {

        if (isdigit(str[i])) {
            ll num = 0;

            while (isdigit(str[i])) {
                num = num * 10 + str[i] - '0';
                i++;
            }

            max_num = max(num, max_num);

        }

        chr.insert(str[i]);
    }

    out << chr.size() << endl << max_num;

    inp.close();
    out.close();

    return 0;
}
