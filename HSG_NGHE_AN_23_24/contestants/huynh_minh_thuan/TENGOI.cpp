#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inp("TENGOI.inp");
    ofstream out("TENGOI.out");

    pair<int, int> ans = {0, 0};
    int n;
    inp >> n;

    while (n--) {

        string name;
        inp >> name;

        string::size_type last = -1;

        for (string::size_type i = 0; i <= name.length(); i++) {
            char c = name[i];

            if (i == name.length() || c == 'W' || c == 'A' || c == 'R') {
                int len = i - last - 1;

                if (len > ans.first) ans = {len, 1};
                else if (len == ans.first) ans.second++;
                last = i;
            }
        }
    }

    if (ans.first) out << ans.first << " " << ans.second;
    else out << "NO";

    inp.close();
    out.close();

    return 0;
}
