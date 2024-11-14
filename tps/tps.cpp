#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string line;

int main() {
    ifstream input("tps.inp");

    int n, k;
    vector<int> a(n);

    input >> n;

    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    input >> k;

    input.close();


}


// 5 987 1000 12345