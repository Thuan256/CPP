#include <bits/stdc++.h>
#define ll long long
using namespace std;

string S;
signed n;

int main() {

    ifstream inp("COUNTSUBSTR.inp");
    ofstream out("COUNTSUBSTR.out");

    getline(inp, S);
    string line;

    getline(inp, line);
    n = stoi(line);

    while (n--) {
        getline(inp, line);

        ll c = 0;
        string::size_type pos = 0;

        while (true) {
            pos = S.find(line, pos);
            if (pos == string::npos) break;
            pos++;
            c++;
        }

        out << c << endl;
    }
    inp.close();
    out.close();

    return 0;
}
