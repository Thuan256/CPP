#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("TSDOAN.INP");
    ofstream out("TSDOAN.OUT");
    int n,d;
    inp>>n>>d;
    vector<int> a(n+1);
    double s=0;
    double kq=0;
    for (int i=1;i<=n;i++)
    {
        int num;
        inp>>num;
        s+=num;
        if (i>=d)
        {
            if (kq<s/i)
                kq=s/(i*1.0);
        }
        a[i]=s;
    }
//    int x=1;
//    while(n-x>=d)
//    {
//        float sum1=a[n]-a[x];
//        float val1=sum1/(n-x)*1.0;
//        if (kq<val1)
//            kq=val1;
//        x++;
//    }
//    int i=1;
//    int j=n;
//    while (j-i>=d)
//    {
//        float sum=a[j]-a[i];
//        float val=sum/(j-i)*1.0;
//        if (kq<val)
//            kq=val;
//        if(j-i==d)
//        {
//            j--;
//            i=1;
//        }
//        i++;
//    }

    for (int i=1;i<=n-d;i++)
    {
        for (int j=i+d;j<=n;j++)
        {
            double sum=a[j]-a[i];
            double val=sum/(j-i)*1.0;
            if (kq<val)
                kq=val;
        }
    }
    out<<fixed<<setprecision(5)<<kq;
    return 0;
}
