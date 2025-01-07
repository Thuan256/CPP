#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("tachmaso.inp");
    ofstream out("tachmaso.out");
    string n;
    inp >> n;
    string k;
    vector<int> A;
    if(isdigit(n[n.size()-1])==true)
        n.push_back('a');
    for(int i=0;i<n.size();i++)
    {
        if(isdigit(n[i])==true)
        {
            k.push_back(n[i]);
        }
        else if(k.size()>0 && isdigit(n[i])==false)
        {
            A.push_back(stoi(k));
            k="";
        }

    }
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++)
    {
        out << A[i]<< " ";
    }
    out.close();
    return 0;
}
