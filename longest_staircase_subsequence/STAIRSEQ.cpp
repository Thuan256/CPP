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

    vector<long long> b;

    while (ss2 >> num) {
        int left = 0, right = b.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            cout << mid << ";";

            if (b[mid] + d <= num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (left && left < b.size()) {
            cout << left << ";;";

            b[left] = num;
        } else {
            cout << num << ";;;" << endl;
            b.push_back(num);
        }
    }

    cout << endl;
    for (auto x : b) cout << x << " ";

    ofstream out("STAIRSEQ.out");
    out << b.size();
    out.close();
    return 0;
}