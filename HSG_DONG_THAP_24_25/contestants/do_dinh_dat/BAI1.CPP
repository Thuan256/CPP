#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("BAI1.INP");
    ofstream out("BAI1.OUT");
    int n,k;
    inp>>n>>k;
    vector<long long> a(n);
    long long sum=0;
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        sum+=num;
        a[i]=sum;
    }
    int i=n-1;
    int kq=0;
    while(i>=0)
    {
        if ((k-a[i]%k)<i)
        {
            out<<i+1;
            return 0;
        }
        i--;
    }
    out<<0;
    return 0;
}
