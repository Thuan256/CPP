#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream inp("BAI3.inp");
    string line;
    getline(inp, line);

    int n, k;
    stringstream ss(line);

    ss >> n;
    ss >> k;
    ss.clear();

    long long a[n], total_price = 0;
    vector<vector<long long>> ranges(k);

    getline(inp, line);
    inp.close();
    ss.str(line);


    for (int i = 0; i < n ; i++)  {
        ss >> a[i];
        ranges[i % k].push_back(a[i]);
    }

    for (auto range: ranges) {
        sort(range.begin(), range.end());
        long long mid = range[range.size() / 2];

        for (long long val: range) {
            total_price += abs(mid - val);
        }
    }

    ofstream out("BAI3.out");
    out << total_price;
    out.close();

    return 0;
}
