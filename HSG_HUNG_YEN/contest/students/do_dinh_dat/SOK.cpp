#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fileinput("SOK.INP");
    string line;
    int n,t;
    getline(fileinput,line);
    istringstream ss(line);
    ss>>n;
    ss>>t;
    ss.clear();

    vector<int> a;
    int num;
    getline(fileinput,line);
    ss.str(line);
    ss.clear();
    while (ss>>num)
        a.push_back(num);
    sort(a.begin(),a.end());

    vector<int> b;
    while (getline(fileinput,line))
    {
        int k;
        ss.str(line);
        ss.clear();
        ss>>k;
        b.push_back(k);
    }
    fileinput.close();

    int dem=1;
    vector<int> ds;
    if (dem<a[0])
    {
        for (int i=1;i<a[0];i++)
            ds.push_back(i);
    }
    for (int i=1;i<a.size();i++)
    {
        if (a[i]-a[i-1]>1)
        {
            for (int j=a[i-1]+1;j<a[i];j++)
                ds.push_back(j);
        }
    }

    ofstream fileout("SOK.OUT");
    for (int i=0;i<b.size();i++)
    {
        fileout<<ds[b[i]-1]<<endl;
    }
    fileout.close();
    return 0;
}
