#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to Find index
int Find_Index(int n, int arr[]) {

  int odd = 0, even = 0;

  // Create two vectors of pair type
  vector<pair<int, int>> v_left, v_right;

  v_left.push_back(make_pair(odd, even));
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] % 2 == 0)
      even++;
    else
      odd++;

    v_left.push_back(make_pair(odd, even));
  }

  odd = 0, even = 0;
  v_right.push_back(make_pair(odd, even));
  for (int i = n - 1; i > 0; i--) {
    if (arr[i] % 2 == 0)
      even++;
    else
      odd++;

    v_right.push_back(make_pair(odd, even));
  }

  reverse(v_right.begin(), v_right.end());

  for (int i = 0; i < v_left.size(); i++) {

    // To check even or odd of Both sides are
    // equal or not
    if (v_left[i].first == v_right[i].first ||
        v_left[i].second == v_right[i].second)
      return i;
  }
  return -1;
}

const int maxN=1000005;
int n, arr[maxN];
// Driver's Function
int main() {
    freopen("Numbers.inp","r",stdin);
    freopen("Numbers.out","w",stdout);
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    int index = Find_Index(n, arr);
    ((index == -1) ? cout << "-1" : cout << index);
    return 0;
}
