#include <bits/stdc++.h>
using namespace std;
void daycon(int i,vector<int>& b,long long sum,vector<int>& ds)
{
    if (i==b.size())
    {
        ds.push_back(sum);
    }
    else
    {
        daycon(i+1,b,sum+b[i],ds);
        daycon(i+1,b,sum,ds);
    }
}
int main()
{
    ifstream inp("CHECK.INP");
    ofstream out("CHECK.OUT");

    string line;
    getline(inp,line);
    istringstream ss(line);
    int n,m;
    ss>>n>>m;
    ss.clear();

    string dong2;
    getline(inp,dong2);

    getline(inp,line);
    ss.str(line);
    vector<int> b;
    int num1;
    while(ss>>num1)
        b.push_back(num1);
    vector<int> ds;
    daycon(0,b,0,ds);
    ds.pop_back();

    istringstream ss1(dong2);
    int num;
    int dem=0;
    while(ss1>>num)
    {
        if (find(ds.begin(),ds.end(),num) != ds.end())
            dem++;
    }
    out<<dem;
    inp.close();
    out.close();
    return 0;
}
