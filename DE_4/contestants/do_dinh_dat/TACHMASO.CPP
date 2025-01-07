#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("TACHMASO.INP");
    ofstream out("TACHMASO.OUT");
    string xau;
    inp>>xau;
    int i=0;
    vector<pair<long long,string>> ds;
    while(i<xau.size())
    {

        if (isdigit(xau[i]))
        {
            string str;
            while(isdigit(xau[i]))
            {
                str+=xau[i];
                i++;
            }
            pair<long long,string> a={stoll(str),str};
            ds.push_back(a);
        }
        i++;
    }
    for (int i=0;i<ds.size();i++)
    {
        for (int j=i;j<ds.size();j++)
        {
            if (ds[i].first>ds[j].first)
                swap(ds[i],ds[j]);
        }
    }
    for (auto x: ds)
        out<<x.second<<" ";
    return 0;
}
