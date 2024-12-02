#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream inp("LSUBPAL.inp");
    string str;

    getline(inp, str);
    int n = stoi(str);

    getline(inp, str);
    inp.close();

    int maxL = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            int left = i;
            int right = left + j;

            while (left >= 0 && left < n && str[left] == str[right]) {
                maxL = max(maxL, right++ - left-- + 1);
            }
        }
    }

    ofstream out("LSUBPAL.out");
    out << maxL;
    out.close();

    return 0;
}