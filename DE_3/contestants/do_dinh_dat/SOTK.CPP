#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("SOTK.INP");
    ofstream out("SOTK.OUT");
    int n,k;
    inp>>n>>k;
    vector<int> a;
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        a.push_back(num);
    }
    set<int> ds(a.begin(),a.end());
    out<<*next(ds.begin(),ds.size()-k);
    return 0;
}
