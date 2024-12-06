#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("CHENHLECH.inp");
    ofstream out("CHENHLECH.out");

    int n;
    string S;

    inp >> n >> S;
    inp.close();

    int ans = 0, max_freq = INT_MIN, min_freq = INT_MAX;
    map<char, int> freq;
    string::size_type i = 0, j = 0;

    for (int i = 0; i < n; i++) {

        char c = S[i];

        freq[c]++;
        max_freq = max(max_freq, freq[c]);

        min_freq = INT_MAX;

        for (auto j = freq.begin(); j != freq.end(); j++) {

            int f = (*j).second;
            if (f > 0) min_freq = min(min_freq, f);
        }

        ans = max(ans, max_freq - min_freq);

    }

    out << ans;
    out.close();
    return 0;
}
