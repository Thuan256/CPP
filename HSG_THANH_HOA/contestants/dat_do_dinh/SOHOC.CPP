#include <bits/stdc++.h>
using namespace std;
vector<bool> sangngto(int n)
{
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for (int p=2;p*p<=n;p++)
    {
        if (prime[p])
        {
            for (int i=p*p;i<=n;i+=p)
                prime[i]=false;
        }
    }
    return prime;
}
int main()
{
    ifstream inp("SOHOC.INP");
    ofstream out("SOHOC.OUT");

    long long n;
    inp>>n;
    vector<bool> ngto=sangngto(20000000);
    if (ngto[n])
    {
        out<<2<<endl;
        out<<n<<endl;
    }
    else
    {
        int dem=0,snt;
        for (int i=1;i<=sqrt(n);i++)
        {
            if (n%i==0)
            {
                int uoc;
                dem+=2;
                uoc=n/i;
                if (ngto[i])
                    snt=i;
                if (ngto[uoc])
                    snt=uoc;
            }
        }
        out<<dem<<endl;
        out<<snt<<endl;
    }
    inp.close();
    out.close();
    return 0;
}
