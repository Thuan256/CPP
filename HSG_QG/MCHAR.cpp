#include <bits/stdc++.h>
#define ll long long;

using namespace std;

int main() {
    ifstream inp("MCHAR.inp");
    ofstream out("MCHAR.out");

    string line;
    getline(inp, line);
    int n = stoi(line);
    int a[n];

    getline(inp, line);
    inp.close();

    stringstream ss(line);
    for (int i = 0; i < n; i++) ss >> a[i];

    int _max = INT_MIN, cur = 0;
    bool order[3] = {0, 1, 0};

    for (int i = 0; i < n - 1; i++) {

        cur++;

        if (a[i] > a[i + 1] && cur > 0) {

            if (a[i - 1] > a[i]) cur = 0;
            int j = i;
            bool valid = 1;

            for (bool ord: order) {

                int tmp = 0;

                while (a[j] < a[j + 1] == ord && j < n - 2) {
                    tmp++;
                    j++;
                }

                cur += tmp;
                valid = !!tmp;

                cout << tmp << endl;
            }

            cout << "cur: " << cur + 1 << endl;
            if (valid) _max = max(cur + 1, _max);
        }
    }

    out << _max;
    out.close();

    return 0;
}
