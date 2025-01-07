#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("square.inp");
    ofstream out("square.out");
    string n;
    inp >> n;
    int s=0;
    int so;
    for(char i:n)
    {
        so=i-'0';
        s += pow(so,2);
    }
    out << s;
    out.close();
    return 0;
}
