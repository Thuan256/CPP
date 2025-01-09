#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream inp("computer.inp");
    ofstream out("computer.out");
    int a1,a2,a3,b1,b2,b3;
    int da1=0;
    int da2=0;
    int da3=0;
    int db1=0;
    int db2=0;
    int db3=0;
    int dbb=0;
    int daa=0;
    inp >> a1 >> a2 >> a3 >> b1>> b2 >> b3;
    int s=0;
    if(a1>=b1)
    {
        s+=b1;
        da1=a1-b1;
    }
    else
    {
        s+=a1;
        db1=b1-a1;
    }
    if(a2>=b2)
    {
        s+=b2;
        da2=a2-b2;
    }
    else
    {
        s+=a2;
        db2=b2-a2;
    }
    daa=da1+da2;
    dbb=db1+db2;
        if(a3>=dbb)
        {
            s+=dbb;
            da3=a3-dbb;
        }
        else
        {
            s+=a3;
            da3=dbb-a3;
        }
    if(b3>=daa)
    {
        s+=daa;
        db3=b3-daa;
    }
    else
    {
        s+=b3;
        db3=daa-b3;
    }
    if(a3!=0 && b3!=0)
        s+=min(da3,db3);
    out << s;
}
