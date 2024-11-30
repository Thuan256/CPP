#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

array<int, 2> _count(string str) {

    array<int,2> rs = {0, 0};

    for (char chr: str) {
        rs[0] += (chr == 'C');
        rs[1] += (chr == 'G');
    }

    return rs;
}

int main() {
    ifstream inp("BAI1.inp");
    string line;

    getline(inp, line);

    int n = stoi(line);
    string virus;
    getline(inp, virus);

    string a[n];

    int _max = 0;
    int index = 0;

    array<int, 2> _virus = _count(virus);
    int c_virus = _virus[0];
    int g_virus = _virus[1];

    for (int i = 0; i < n; i++) {
        getline(inp, a[i]);

        array<int, 2> RNA = _count(a[i]);
        int c = RNA[0];
        int g = RNA[1];

        int point = c_virus * g + g_virus * c;

        if (point > _max) {
            _max = point;
            index = i;
        }
    }

    ofstream out("BAI1.out");
    out << index + 1;
    out.close();

    return 0;
}
