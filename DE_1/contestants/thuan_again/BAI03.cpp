#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ifstream infile("BAI03.INP");
    ofstream outfile("BAI03.OUT");

    int n;
    infile >> n;

    vector<int> a(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; ++i) {
        infile >> a[i];
        freq[a[i]]++;
    }

    unordered_map<int, bool> isAvgCounted;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int avg = a[i] + a[j];
            if (avg % 2 == 0) {
                avg /= 2;
                if (freq.find(avg) != freq.end() && !isAvgCounted[avg]) {
                    result++;
                    isAvgCounted[avg] = true;
                }
            }
        }
    }

    outfile << result << endl;
    infile.close();
    outfile.close();
    return 0;
}
