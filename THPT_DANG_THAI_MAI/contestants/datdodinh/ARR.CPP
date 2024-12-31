#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("ARR.INP");
    ofstream out("ARR.OUT");
    int n;
    inp>>n;
    unordered_map<int, bool> m;
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;

        if (!m[num]) out << num << " ";
        m[num] = true;
    }
    return 0;
}
