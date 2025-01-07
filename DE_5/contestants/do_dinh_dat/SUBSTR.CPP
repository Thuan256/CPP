#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("SUBSTR.INP");
    ofstream out("SUBSTR.OUT");
    int k;
    inp>>k;
    string xau;
    inp>>xau;
    int kq=0;
    for (int i=0;i<xau.size();i++)
    {
        int d=0;
        int j=i;
        while (j<xau.size())
        {
            if (xau[j]=='1')
                d++;
            if (d==k)
            {
                kq++;
                j++;
                while(xau[j]=='0')
                {
                    kq++;
                    j++;
                }
                break;
            }

            j++;
        }
    }
    out<<kq;
    return 0;
}
