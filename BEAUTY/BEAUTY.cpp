#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("BEAUTY.inp");
    ofstream out("BEAUTY.out");

    int n;
    inp >> n;
    string num = "0";
    int sum = 0;

    while (n) {
        for (int i = num.length() - 1; i >= 0; i--) {

            if (num[i] < '9') {
                sum ++;
                num[i]++;
                break;
            } else {
                num[i] = '0';
                sum -= 9;
            }
        }

        if (num[0] == '0') {
            num = '1' + num;
            sum++;
        }

        if (sum % num.length() == 0) n--;
    }
    out << num;
    inp.close();
    out.close();
    return 0;
}
