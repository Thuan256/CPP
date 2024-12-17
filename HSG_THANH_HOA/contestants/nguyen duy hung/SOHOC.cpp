#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("SOHOC.INP");
    ofstream out("SOHOC.OUT");
    int n;
    inp >> n;
    vector<int> A;
    vector<int> B;
    vector<bool> hams(10e6+1,true);
    hams[0] = hams[1] = false;
    for(int p =2; p*p<=10e6+1;p++){
            if(hams[p] == true){
                    for (int i=p*p;i<=10e6+1;i+=p)
                        hams[i] = false;
            }
           }
    int b;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
            {A.push_back(i);
            if(hams[i]==true)
                B.push_back(i);}
    }
    out << A.size() << endl;
    out << B[B.size()-1];
    out.close();
    return 0;
}

