#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("SAFE.inp");
    ofstream out("SAFE.out");

    int n;
    string S;
    inp >> n >> S;
    long long ans = 0;

    // lower, upper, number
    int v[3] = {0, 0, 0};

    string::size_type i = 0, j = 0;


    while (i < n) {

        while (!(v[0] && v[1] && v[2] && j - i > 6) && j < n) {
            char c = S[j];
            if (isdigit(c)) v[2]++;
            else if (isupper(c)) v[1]++;
            else if (islower(c)) v[0]++;

            j++;
        }

        ans += n - j + 1;
        i++;

        char c = S[i];
        if (isdigit(c)) v[2]--;
        else if (isupper(c)) v[1]--;
        else if (islower(c)) v[0]--;

        cout << v[0] << " " << v[1] << " " << v[2] << endl;
        cout << i << " " << j << " " << endl;

    }

    cout << ans;
}
