#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    ifstream fileinput("BAI1.INP");
    string line;
    getline(fileinput,line);
    int n = stoi(line);
    vector<string> a;
    while (getline(fileinput,line))
    {
        string str;
        istringstream ss1(line);
        while (ss1>>str)
            a.push_back(str);
    }
    int C1=0,G1=0;
    for (char x: a[0])
    {
        if ('C'==x)
            C1++;
        else if ('G'==x)
            G1++;
    }

    int dem=1;
    int soluong=0;
    for (int i=1;i<a.size();i++)
    {
        int sl=0;
        int Ci=0,Gi=0;
        for (char x:a[i])
        {
            if ('C'==x)
            Ci++;
        else if ('G'==x)
            Gi++;
        }
        sl=Gi*C1+Ci*G1;
        if (soluong<sl)
        {
            dem=i;
            soluong=sl;
        }
    }
    ofstream fileout("BAI1.OUT");
    fileout<<dem;
    fileout.close();
    return 0;
}
