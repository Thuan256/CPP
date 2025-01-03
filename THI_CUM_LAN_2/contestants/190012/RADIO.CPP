#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("RADIO.INP");
    ofstream out("RADIO.OUT");
    int n;
    string xau;
    inp>>n>>xau;
    int kq=0;
    for (int i=0;i<n;i++)
    {
        int j=0;
        int k=i+1;
        int g=0,h=0;
        while(k<n && j<n-k+1)
        {
            string s=xau.substr(j,k);
            string x=xau.substr(j+k,k);
            if (x == s)
            {
                j++;
                h=s.size();
            }
            else
            {
                j+=k;
            }
            if (j==n-k)
            {
                j=0;
                k++;
            }

        }
        if (kq<h)
            kq=h;
    }
    out<<kq;
    return 0;
}
