#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("LIS.inp");
    ofstream out("LIS.out");

    int n;
    inp >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) inp >> nums[i];

    vector<unsigned int> a;

    a.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (a.back() < nums[i]) {
            a.push_back(nums[i]);
        } else {
            int low = lower_bound(a.begin(), a.end(), nums[i]) - a.begin();
            a[low] = nums[i];
        }
    }

    out << a.size();
    out.close();
    return 0;
}
