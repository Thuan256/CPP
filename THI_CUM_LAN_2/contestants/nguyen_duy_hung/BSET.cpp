#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("BSET.INP");
    ofstream out("BSET.OUT");
    int a,b;
    inp >> a >> b;
    vector<int> A;
    vector<int> B;
    while(a--)
    {
        int num;
        inp >> num;
        A.push_back(num);
    }
    while(b--)
    {
        int num1;
        inp >> num1;
        B.push_back(num1);
    }
    int k=0;
    for(int i=0;i<B.size();i++)
        {for(int j=0;j<A.size();j++)
            {if(A[j]==B[i])
                k++;}}
    out << A.size() + B.size() - k << " " << k;
    out.close();
    return 0;
}
