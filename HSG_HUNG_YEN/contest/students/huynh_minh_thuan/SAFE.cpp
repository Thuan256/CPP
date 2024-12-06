#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("SAFE.inp");
    ofstream out("SAFE.out");

    int n;
    string S;
    inp >> n >> S;

    if (n < 6) {
        out << 0;
        return 0;
    }

    long long ans = 0;

    string::size_type i = 0, j = 0;
    int v[3] = {0, 0, 0};

    for (int j = 0; j < n; ++j) {
        if (islower(S[j])) v[0]++;
        else if (isupper(S[j])) v[1]++;
        else if (isdigit(S[j])) v[2]++;

        while (j - i + 1 >= 6 && v[0] > 0 && v[1] > 0 && v[2] > 0) {
            ans += n - j;
            if (islower(S[i])) v[0]--;
            else if (isupper(S[i])) v[1]--;
            else if (isdigit(S[i])) v[2]--;
            i++;
        }
    }

    out << ans;
    inp.close();
    out.close();
    return 0;
}


