#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fileinput("NUMBERS.INP");
    string line;
    int n;
    getline(fileinput,line);
    istringstream ss(line);
    ss>>n;
    ss.clear();

    vector<int> a;
    getline(fileinput,line);
    ss.str(line);
    ss.clear();
    int num,demchan=0,demle=0;
    while (ss>>num)
    {
        a.push_back(num);
        if (num%2==0)
            demchan++;
        else
            demle++;
    }
    fileinput.close();
    ofstream fileout("NUMBERS.OUT");
    int demchan1=0,demle1=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]%2==0)
        {
            demchan1++;
            demchan--;
        }
        else if(a[i]%2 !=0)
        {
            demle1++;
            demle--;
        }
        if (demchan1 - 1==demchan || demle1 - 1==demle)
        {

            fileout<<i;
            break;
        }
    }
    fileout.close();
    return 0;
}
