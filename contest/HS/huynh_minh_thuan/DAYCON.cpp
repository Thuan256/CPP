#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream inp("DAYCON.INP");
    string line;

    cout << line;

    getline(inp, line);

    stringstream ss(line);

    int n, m;
    ss >> n;
    ss >> m;

    vector<int> a(n);

    getline(inp, line);
    inp.close();

    stringstream ss1(line);

    for (int i = 0; i < n; i++) ss1 >> a[i];

    int left = 0, right = 0;
    long long sum = 0, count = 0;

    while (right < n) {
        sum += a[right];

        while (sum > m && left <= right) {
            sum -= a[left];
            left++;
        }

        count += (right - left + 1);
        right++;
    }

    ofstream out("DAYCON.OUT");

    out << count;
    out.close();

    return 0;
}