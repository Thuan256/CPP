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
int daoso(int i)
{
    string xau=to_string(i);
    string s;
    for (int i=xau.size()-1;i>=0;i--)
        s+=xau[i];
    return stoi(s);
}
int main()
{
    ifstream inp("BAI02.INP");
    ofstream out("BAI02.OUT");
    int a,b;
    inp>>a>>b;
    vector<bool> prime=snt(10000000);
    int kq=0;
    for (int i=a;i<=b;i++)
    {
        if (prime[i]==true && prime[daoso(i)]==true)
            kq++;
    }
    out<<kq;
    inp.close();
    out.close();
    return 0;
}
