#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream inp("LIS.inp");
    string line;

    getline(inp, line);
    int n = stoi(line);
    vector<unsigned int> nums;

    getline(inp, line);
    inp.close();
    stringstream ss(line);

    int num;

    while (ss >> num) nums.push_back(num);

    vector<unsigned int> a;

    a.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > a.back()) {
            a.push_back(nums[i]);
        } else {
            int low = lower_bound(a.begin(), a.end(), nums[i]) - a.begin();

            a[low] = nums[i];
        }
    }

    ofstream out("LIS.out");
    out << a.size();
    out.close();
    return 0;
}