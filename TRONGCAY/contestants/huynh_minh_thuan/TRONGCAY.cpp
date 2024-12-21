#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("TRONGCAY.inp");
    ofstream out("TRONGCAY.out");

    int n, k;
    inp >> n >> k;

    vector<int> heights(n);

    for (size_t i = 0; i < n; i++) inp >> heights[i];

    int fixed_tree = heights[k - 1];

    heights.erase(heights.begin() + k - 1);

    sort(heights.begin(), heights.end());

    heights.insert(lower_bound(heights.begin(), heights.end(), fixed_tree), fixed_tree);

    int ans = 0;

    for (size_t i = 1; i < heights.size(); i++) {
        ans += abs(heights[i] - heights[i - 1]);
    }

    out << ans;

    return 0;
}
