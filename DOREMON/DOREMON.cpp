#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int daycon(vector<int>& ds, vector<vector<int>>& rs, int a[], int n) {
    if (ds.size() == n) {
        rs.push_back(ds);
        return 0;
    }
    for (int i = 0; i < 2; i++) {
        ds.push_back(a[i]);
        daycon(ds, rs, a, n);
        ds.pop_back();
    }
}
int main() {
    ifstream fileinput("DOREMON.INP");
    string line;
    vector<int> b;
    getline(fileinput, line);
    istringstream ss(line);

    short n,k;

    ss >> n;
    ss >> k;

    fileinput.close();

    vector<int> ds;
    vector<vector<int>> rs;

    int a[2] = {0, 1};
    long long d = 0;

    daycon(ds, rs, a, n);
    for (int i = 0; i < rs.size(); i++) {
        vector<int> dp(n, 0);
        int sl = 1;
        for (int j = 0; j < rs[i].size(); j++) {
            if (rs[i][j] == rs[i][j - 1])
                dp[j] = dp[j - 1] + 1;
            else
                dp[j] = 1;
            if (sl < dp[j]) sl = dp[j];
        }
        if (sl <= k) {

            for (int x: rs[i]) {
                cout << x;
            }
            cout << endl;
            d++;
        }
    }
    ofstream fileout("DOREMON.OUT");
    fileout << d;
    fileout.close();
    return 0;
}
