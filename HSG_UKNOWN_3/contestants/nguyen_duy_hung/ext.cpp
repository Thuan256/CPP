#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("ext.inp");
    ofstream out("ext.out");
    int n,a;
    int k=0;
    inp >> n;
    vector<int> A;
    while(inp >> a)
    {
        A.push_back(a);
    }
    for(int i=1;i<n-1;i++)
    {
        if(A[i]>A[i-1] && A[i]>A[i+1] )
            k++;
        else if(A[i]<A[i-1] && A[i]<A[i+1])
            k++;
    }
    out << k;
    out.close();
    return 0;
}
