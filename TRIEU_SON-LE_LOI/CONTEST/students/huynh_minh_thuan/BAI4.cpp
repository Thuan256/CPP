#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string test(string* lines) {
    stringstream ss;

    ss.str(lines[0]);
    ss.clear();

    int n, k;
    ss >> n;
    ss >> k;

    ss.str(lines[1]);
    ss.clear();

    int num;
    map<int, int> _map;

    while (ss >> num) {
        if (num < k) _map[num]++;
    }

    for (pair<int, int> p : _map) {
        int value = p.first;
        int count = p.second;

        if (value >= k) return "YES";

        _map[value + 1] += count / (value + 1);

        if (count % (value + 1)) return "NO";
    }
    return "YES";
}

int main() {
    ifstream inp("BAI4.inp");
    ofstream out("BAI4.out");
    string line;
    getline(inp, line);

    short t = stoi(line);

    vector<vector<string>> lines;

    int maxK = 0;

    while (t--) {
        string line1, line2;

        getline(inp, line1);
        getline(inp, line2);

        string _case[2] = {line1, line2};

        out << test(_case) << endl;
    }

    inp.close();
    out.close();

    return 0;
}
