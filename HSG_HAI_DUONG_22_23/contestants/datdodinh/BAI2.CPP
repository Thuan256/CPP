#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("BAI2.INP");
    ofstream out("BAI2.OUT");
    int n;
    string xau;
    inp>>n>>xau;
    int tong=0;
    int kq=0;
    int i=0;
    while (i<n)
    {
        if (xau[i]=='1')
        {
            tong=0;
            int sum=0;
            while (xau[i]=='1')
            {
                i++;
                sum++;
                tong+=sum;
            }
            kq+=tong;
        }
        i++;
    }
    out<<kq;
    inp.close();
    out.close();
    return 0;

}
