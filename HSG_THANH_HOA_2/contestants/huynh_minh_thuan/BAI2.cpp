#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("BAI2.inp");
    ofstream out("BAI2.out");

    int n, k, range = 0;
    string str;
    inp >> n >> k >> str;

    for (int i = 1; i < str.size(); i++) {
        if (str[i] == str[i - 1]) range += 2;
        else range++;
    }

    while (k--) {
        int index;
        inp >> index;

        index--;

        if (index > 0) {
            if (str[index - 1] != str[index]) range++;
            else range--;
        }

        if (index < str.size() - 1) {
            if (str[index + 1] != str[index]) range++;
            else range--;
        }

        str[index] = (str[index] == '0' ? '1' : '0');

        out << range << endl;
    }

    inp.close();
    out.close();

    return 0;
}
