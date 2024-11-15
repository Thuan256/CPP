#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream inp("STAIRSEQ.inp");

    int n;
    long long d;
    string line;

    getline(inp, line);
    stringstream ss1(line);
    ss1 >> n;
    ss1 >> d;
    vector<long long> a;
    long long num;

    getline(inp, line);
    inp.close();
    stringstream ss2(line);

    while (ss2 >> num) a.push_back(num);

    vector<long long> b;
    b.push_back(a[0]);

    int left = 0, right = 0, maxLength = 0;
    long long sum = 0;

    for (int i = 1; i < n; i++) {
        long long dif = a[i] - b.back();

        if (0 < dif && dif >= d) {
            b.push_back(a[i]);
        } else {
            int low = lower_bound(a.begin(), b.end(), a[i]) - b.begin();

            b[low] = a[i];
        }
    }

    ofstream out("STAIRSEQ.out");
    out << b.size();
    out.close();
    return 0;
}