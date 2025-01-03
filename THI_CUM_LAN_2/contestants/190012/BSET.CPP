#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("BSET.INP");
    ofstream out("BSET.OUT");
    int n,m;
    inp>>n>>m;
    vector<int> x;
    vector<int> y;
    for (int i=0;i<n;i++)
    {
        int num;
        inp>>num;
        x.push_back(num);
    }
    for (int i=0;i<m;i++)
    {
        int num;
        inp>>num;
        y.push_back(num);
    }
    set<int> a(x.begin(),x.end());
    set<int> b(y.begin(),y.end());
    int giong=0;
    for (auto i:a)
    {
        for (auto j:b)

        {
            if (i==j){
                giong++;
                break;}
        }
    }
    out<<a.size()+b.size()-giong<<" "<<giong;
    inp.close();
    out.close();
    return 0;
}
