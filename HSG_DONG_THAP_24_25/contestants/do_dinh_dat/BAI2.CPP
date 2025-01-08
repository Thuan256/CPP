#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("BAI2.INP");
    ofstream out("BAI2.OUT");
    string line;
    getline(inp,line);
    int n=stoi(line);

    string line1,line2;
    getline(inp,line1);
    istringstream ss1(line1);
    getline(inp,line2);
    istringstream ss2(line2);
    vector<double> a(n);
    for (int i=0;i<n;i++)
    {
        double num1,num2;
        ss1>>num1;
        ss2>>num2;
        a[i]=num1/num2;

    }
    vector<int> ds(n,1);
    int kq=0;
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (a[i]>a[j])
                ds[i]=max(ds[i],ds[j]+1);
        }
        if (kq<ds[i])
            kq=ds[i];
    }
    out<<kq;
    return 0;
}
