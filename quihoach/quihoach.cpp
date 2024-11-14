#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {

    ifstream input("quihoach.inp");

    int n;
    input >> n;

    vector<string> a(n);

    for (int i = 0; i < n; ++i) {
        input >> a[i];
    }

    input.close();

    vector<int> maxValues;

    for (auto street : a) {

        unordered_set<char> houses(street.begin(), street.end());
        vector<int> counts(houses.size());

        for (char house : houses) {
            counts.push_back(std::count(street.begin(), street.end(), house));
        }

        int maxValue = *std::max_element(counts.begin(), counts.end());

        maxValues.push_back(maxValue);
    }

    int max = *std::max_element(maxValues.begin(), maxValues.end());
    cout << max;

    return 0;
}