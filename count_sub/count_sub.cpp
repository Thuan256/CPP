#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    ifstream inp("count_sub.inp");

    string line;
    getline(inp, line);

    stringstream ss1(line);

    int n, k;
    ss1 >> n;
    ss1 >> k;

    getline(inp, line);
    inp.close();

    stringstream ss2(line);
    int a[n];

    for (int i = 0; i < n; i++) ss2 >> a[i];
    int sum = 0, left = 0, right = 0, count = 0;

    while (right < n) {
        sum += a[right];

        while (sum >= k) {
            count += (n - right);
            sum -= a[left];
            left++;
        }

        right++;
    }

    ofstream out("count_sub.out");

    out << count;
    out.close();
}