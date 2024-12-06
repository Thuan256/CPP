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

//    for (int i = 0; i < n - 1; i++) {
//        pair<char, int> most = {' ', INT_MIN};
//        pair<char, int> least = {' ', INT_MAX};
//        map<char, int> occ;
//
//        for (int j = i + 1; j < n ; j++) {
//
//            char c = S[j];
//            occ[c]++;
//
//            if (c == most.first) most.second++;
//            else if (occ[c] > most.second) {
//                most = {c, occ[c]};
//            }
//
//            if (c == least.first) least.second++;
//            else if (occ[c] < least.second) {
//                least = {c, occ[c]};
//            }
//        }
//
//        if (most.second > 0 && least.second > 0) ans = max(ans, most.second - least.second);
//    }

    out << ans;
    out.close();
    return 0;
}
