#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("TG.INP");
    ofstream out("TG.OUT");
    long long a,b,k,n;
    long long s=10e10;
    inp >> a >> b;
    for(long long i=(a+b)/2;i<=b;i++)
    {
        k=abs((i-a+1)*(2*a+i-a-1)-(b-i)*(2*i+b-i));
        if(k<s)
        {
            s=k;
            n=i;
        }

    }
    out << n;
    out.close();
    return 0;

}
