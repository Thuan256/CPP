#include <algorithm>
#include <cmath>
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
                int count_i = 1, count_j = 1;

                while (i + 1 < j && a[i] == a[i + 1]) {
                    count_i++;
                    i++;
                }
                while (j - 1 > i && a[j] == a[j - 1]) {
                    count_j++;
                    j--;
                }
                count += count_i * count_j;
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