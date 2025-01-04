#include <bits/stdc++.h>
using namespace std;
vector<bool> sochinhphuong(int n)
{
    vector<bool> chinhphuong(n+1,false);
    for (int i=1;i*i<n;i++)
    {
        int num=i*i;
        chinhphuong[num]=true;
    }
    return chinhphuong;
}
int tachso(long long n)
{
    int tong=0;
    while(n>0)
    {
        tong+=n%10;
        n/=10;
    }
    return tong;
}
int main()
{
    ifstream inp("BAI01.INP");
    ofstream out("BAI01.OUT");
    long long n;
    inp>>n;
    vector<bool> a=sochinhphuong(162);
    int num=tachso(n);
    if (a[num]==true)
        out<<num;
    else
        out<<num%11;
    inp.close();
    out.close();
    return 0;
}
