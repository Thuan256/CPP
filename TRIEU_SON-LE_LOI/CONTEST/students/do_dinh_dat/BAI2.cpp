#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
int main()
{
    ifstream fileinput("BAI2.INP");
    string line;
    int n,k;
    getline(fileinput,line);
    istringstream ss(line);
    ss>>n;
    ss>>k;

    vector<int> a;
    getline(fileinput,line);
    for (char x: line)
        a.push_back(x - '0');

    int num;
    getline(fileinput,line);
    istringstream ss1(line);
    ofstream fileout("BAI2.OUT");
    while(ss1>>num)
    {
        if (a[num-1]==0)
            a[num-1]=1;
        else
            a[num-1]=0;
        int d=0;


        for (int j=0;j<a.size()-1;j++)
        {
            if (a[j+1]==a[j])
                d+=2;
            else
                d+=1;
        }
        fileout<<d<<endl;
    }
    fileinput.close();
    fileout.close();
    return 0;

}
