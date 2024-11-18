#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream inp("SUBPAL.inp");
    string str;
    getline(inp, str);

    inp.close();

    int n = str.length();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            int left = i;
            int right = left + j;

            while (left >= 0 && left < n && str[left] == str[right]) {
                count++;
                left--;
                right++;
            }
        }
    }

    ofstream out("SUBPAL.out");
    out << count;
    out.close();
}