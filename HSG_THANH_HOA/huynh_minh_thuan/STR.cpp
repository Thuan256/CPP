#include <bits/stdc++.h>
#define ll long long
using namespace std;

string greater_str(string a, string b) {
    if (a.length() > b.length()) return a;
    if (a.length() < b.length()) return b;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] > b[i]) return a;
        if (a[i] < b[i]) return b;
    }

    return a;
}

int main() {
    ifstream inp("STR.inp");
    ofstream out("STR.out");

    string str;
    inp >> str;

    int n = str.length(), i = 0;
    string max_num = "0";
    unordered_set<char> chr;

    while (i < n) {
        if (islower(str[i])) {
            chr.insert(str[i]);
            i++;
        }
        else {
            string num = "";

            while (isdigit(str[i])) {
                if (num.length()) num.push_back(str[i]);
                else if (str[i] != '0') num.push_back(str[i]);
                i++;
            }

            max_num = greater_str(num, max_num);
        }
    }

    out << chr.size() << endl << max_num;

    inp.close();
    out.close();

    return 0;
}
