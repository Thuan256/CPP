#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("STR.INP");
    ofstream out("STR.OUT");
    string xau;
    inp>>xau;
    set<char> ds(xau.begin(),xau.end());
    int dem=0;
    for (char x: ds)
    {
        if (islower(x))
            dem++;
    }

    int gtri=0;
    int i=0;
    while (i<xau.size())
    {
        if (isdigit(xau[i]))
        {
            int num=0;
            while (isdigit(xau[i]))
            {
                num=num*10 + xau[i]-'0';
                i++;
            }
            if (gtri<num)
                gtri=num;
        }
        i++;
    }
    out<<dem<<endl;
    out<<gtri;
    return 0;
}
