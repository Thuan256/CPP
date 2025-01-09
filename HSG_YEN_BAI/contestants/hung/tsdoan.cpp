#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("tsdoan.inp");
    ofstream out("tsdoan.out");
    int n,d,a;
    double c;
    double s=0;
    double b=0;
    inp >> n >> d;
    vector<int> A;
    while(n--)
    {
        inp >> a;
        s+=a;
        A.push_back(s*1.0);
    }
    int i=0;
    while(i<A.size())
    {
        int j=0;
        while(i+j<A.size())
        {
            if(j>=d)
            {
                c=1.0*(A[i+j]-A[i])/j;
                if(c>b)
                    b=c;
            }
            j++;

        }
        i++;
    }
    out << fixed << setprecision(5) << b;
    out.close();
    return 0;
}
