#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream inp("TGVUONG.inp");
    string line;

    getline(inp, line);

    short n = stoi(line);
    vector<long long> a;

    getline(inp, line);
    inp.close();

    stringstream ss(line);

    for (int i = 0; i < n; i++) {
        int num;
        ss >> num;
        a.push_back(static_cast<long long>(num) * num);
    };

    sort(a.begin(), a.end());

    int count = 0;

    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;

        while (i < j) {
            long long sum = a[i] + a[j];

            if (sum == a[k]) {
                count++;
                i++;
                j--;
            } else if (sum < a[k])
                i++;
            else
                j--;
        }
    }

    ofstream out("TGVUONG.OUT");
    out << count;
    out.close();
    return 0;
}