#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fileinput("FACTORIAL.INP");
    int n;
    string line;
    getline(fileinput,line);
    istringstream ss(line);
    ss>>n;
    fileinput.close();

    long long tong=0;
    long long giaithua=1;
    for (int i=1;i<=n;i++)
    {
        giaithua*=i;
        tong+=giaithua;
    }

    ofstream fileout("FACTORIAL.OUT");
    fileout<<tong%20240131;
    fileout.close();
    return 0;
}
