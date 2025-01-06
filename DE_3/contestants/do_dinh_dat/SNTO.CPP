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
bool ktra(long long n)
{
    int kq=0;
    for (int i=1;i<=sqrt(n);i++)
    {
        if (n%i==0)
        {

            kq++;
            {
                if (i != n/i)
                    kq++;
            }
        }
        if (kq>2)
        {
            return false;
        }
    }
    return true;

}
int main()
{
    ifstream inp("SNTO.INP");
    ofstream out("SNTO.OUT");
    int n;
    inp>>n;
    int kq1=0;
    long long kq2=0;
    vector<bool> prime=snt(20000000);
    for (int i=0;i<n;i++)
    {
        long long num;
        inp>>num;
        if (num>0)
        {
            if(num<=20000000)
            {
                if (prime[num]==true)
                {
                    kq1++;
                    if (kq2<num)
                        kq2=num;
                }
            }
            else
            {
                if (ktra(num)==true)
                {
                    kq1++;
                    if (kq2<num)
                        kq2=num;
                }
            }
        }
    }
    out<<kq1<<endl<<kq2;
    return 0;
}
