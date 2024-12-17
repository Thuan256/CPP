#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("POLE.INP");
    ofstream out("POLE.OUT");

    int n,c;
    string line;
    getline(inp,line);
    istringstream ss(line);
    ss>>n>>c;
    ss.clear();

    vector<int> h;
    while(getline(inp,line))
    {
        ss.str(line);
        ss.clear();
        int num;
        ss>>num;
        h.push_back(num);
    }
    vector<int> a=h;
    int vitrimin=*min_element(h.begin(),h.end());
    int vitrimax=*max_element(h.begin(),h.end());
    for (int i=0;i<a.size();i++)
    {
        if (vitrimax==a[i]){
            vitrimax=i;
            break;}
    }
    for (int i=0;i<a.size();i++)
    {
        if (vitrimin==a[i])
            vitrimin=i;
    }

    vector<int> chiphi;
    while(h[vitrimin]<h[vitrimax])
    {
        h[vitrimin]++;
        int gia=0;
        int dem=0;
        int gia1=0;
        for (int i=0;i<h.size();i++){
            gia1+=(h[i]-a[i])*(h[i]-a[i]);
            if (i>0)
                dem+=abs(h[i]-h[i-1]);
        }
        gia=c*dem+gia1;
        chiphi.push_back(gia);


        int giatrimin;
        giatrimin=*min_element(h.begin(),h.end());

        for (int i=0;i<h.size();i++)
        {
            if (giatrimin==h[i])
                vitrimin=i;
        }
    }

    out<<*min_element(chiphi.begin(),chiphi.end());
    inp.close();
    out.close();
}
