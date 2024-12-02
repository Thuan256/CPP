#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fileinput("BAI4.INP");
    ofstream fileout("BAI4.OUT");
    string line;
    int t;
    getline(fileinput,line);
    stringstream ss(line);
    ss.clear();
    ss>>t;

    for (int i=1;i<=t;i++)
    {
        int n,k;
        getline(fileinput,line);
        ss.str(line);
        ss.clear();
        ss>> n;
        ss>>k;

        int num;
        vector<int> a;
        getline(fileinput,line);
        ss.str(line);
        ss.clear();
        while(ss>>num)
            a.push_back(num);
        sort(a.begin(),a.end());
        if (k<=a[0])
                fileout<<"YES"<<endl;
        else
                fileout<<"NO"<<endl;
    }
    fileinput.close();
    fileout.close();
    return 0;
}
