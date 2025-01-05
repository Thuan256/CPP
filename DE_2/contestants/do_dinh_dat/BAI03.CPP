#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("BAI03.INP");
    ofstream out("BAI03.OUT");
    int d,n;
    inp>>d>>n;
    vector<int> a;
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        a.push_back(num);
    }
    int kq=0;
    for (int i=0;i<n;i++)
    {
        int s=0;
        for (int j=i;j<n;j++)
        {
            s+=a[j]%d;
            if (s%d==0)
                kq++;
        }
    }
    out<<kq;
    return 0;
}
