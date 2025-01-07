#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("SOTK.inp");
    ofstream out("SOTK.out");
    int n,k,a;
    inp >>n >> k;
    vector<int> A;
    while(n--)
    {
        inp >> a;
        A.push_back(a);
    }
    set<int> B(A.begin(),A.end());
    out <<*next(B.begin(),B.size()-k);
    out.close();
    return 0;
}
