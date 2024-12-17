#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("candy.inp");
    ofstream out("candy.out");
    int n;




    vector<int> A;
    while(inp >> n)
        A.push_back(n);
    vector<int> B;
    vector<int> C;
    C.push_back(A[A.size()-1]);
    int b=0;
    int c=A[A.size()-1];
    for(int i=0;i<A.size()-1;i++)
    {
        if(b<=c)
        {
            B.push_back(A[i]);
            b=b+A[i];
        }
        else{
            C.push_back(A[i]);
            c=c+A[i];
        }
    }
    out << b << " " << c << " " << abs(b-c) << endl;
    for(int i=0;i<B.size();i++)
    {
        out << B[i] << " ";
    }
    out << endl;
    for(int i=0;i<C.size();i++)
    {
        out << C[i] << " ";
    }

}
