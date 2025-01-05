#include <bits/stdc++.h>
using namespace std;
vector<bool> snt(int n)
{
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for (int p=2;p*p<=n;p++)
    {
        if (prime[p]==true)
        {
            for (int i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
    return prime;
}
bool ktra(int n)
{
    string xau=to_string(n);
    if (xau.size()==1)
        return false;
    else
    {
        int d=1;
        for (int i=0;i<xau.size()-1;i++)
        {
            if (xau[i+1]>xau[i])
                d++;
        }
        if (d==xau.size())
            return true;
        else
            return false;
    }
}
int main()
{
    ifstream inp("BAI02.INP");
    ofstream out("BAI02.OUT");
    int n;
    inp>>n;
    int kq=0;
    vector<bool> prime=snt(2000000);
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        if (ktra(num)==true && prime[num]==true)
            kq++;
    }
    out<<kq;
    return 0;
}
