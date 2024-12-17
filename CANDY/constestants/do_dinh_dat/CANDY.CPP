#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("CANDY.INP");
    ofstream out("CANDY.OUT");
    vector<int> a;
    string line;
    int tong=0;
    while(getline(inp,line))
    {
        int num;
        num=stoi(line);
        tong+=num;
        a.push_back(num);
    }

    int sum=0,chenhlech=tong,index,tongtrai=0,tongphai=0;
    for (int i=0;i<a.size();i++)
    {
        sum+=a[i];
        if (chenhlech>abs(sum-(tong-sum)) && tong-sum != 0)
        {
            chenhlech=abs(sum-(tong-sum));
            index=i;
            tongtrai+=a[i];

        }
    }
    tongphai=tong-tongtrai;
    out<<tongtrai<<" "<<tongphai<<" "<<chenhlech<<endl;
    int d=0;
    for (int i=0;i<a.size();i++)
    {
        if (i<=index)
        {
            out<<a[i]<<" ";
        }
        else
        {
            d++;
            if (d==1)
                out<<endl;
            out<<a[i]<<" ";
        }
    }
    return 0;

}
