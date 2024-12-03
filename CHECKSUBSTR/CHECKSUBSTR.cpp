#include <bits/stdc++.h>
using namespace std;

string S;
signed n;

int main() {

    ifstream inp("CHECKSUBSTR.inp");
    ofstream out("CHECKSUBSTR.out");

    getline(inp, S);
    string line;

    getline(inp, line);
    n = stoi(line);

    while (n--) {
        getline(inp, line);

        out << (S.find(line) != string::npos ? "Yes\n" : "No\n");
    }
    inp.close();
    out.close();

    return 0;
}
