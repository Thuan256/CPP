#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("DIVISION.INP");
    ofstream out("DIVISION.OUT");
    int t;
    inp>>t;
    for (int i=0;i<t;i++)
    {
        int x,l;
        string xau;
        inp>>x>>l>>xau;
        int dem=0;
        for (int i=0;i<xau.size();i++)
            {
                string str=xau.substr(i,l);
                int num=stoi(str);
                if (to_string(num).size()==l && num % x ==0)
                    dem++;
            }
        out<<dem<<endl;
    }
    inp.close();
    out.close();
    return 0;
}
