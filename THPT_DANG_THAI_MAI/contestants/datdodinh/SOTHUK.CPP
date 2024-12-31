#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("SOTHUK.INP");
    ofstream out("SOTHUK.OUT");
    int t,n,m,k;
    inp>>t;
    for (int i=0;i<t;i++)
    {
        inp>>n>>m>>k;
        vector<int> a;
        for (int j=0;j<m;j++)
        {
            int num;
            inp>>num;
            a.push_back(num);
        }
        int sl;
        if (a[0]==1)
            sl=0;
        else
            sl=a[0]-1;
        cout<<sl<<" ";
        if (sl>=k)
            out<<k<<endl;
        else
        {   k=k-sl;
            int kq=-1;
            for (int j=1;j<m;j++)
            {
                sl=a[j]-a[j-1]-1;
                if (sl>=k && a[j-1]<n)
                {
                    kq=a[j-1]+k;
                    break;
                }
                else
                    k=k-sl;
            }
            out<<kq<<endl;
        }
    }
    return 0;
}
