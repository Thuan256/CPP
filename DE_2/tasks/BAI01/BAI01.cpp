#include <bits/stdc++.h>
using namespace std;
long long a,b,n,m;
long long base1=1000000000;

long long fastpow(long long x, long long n) {
    long long res=1;
    while (n>0) {

        if(n%2==1) res=res*x;
        res=res%base1;
        x*=x;
        x=x%base1;
        n=n/2;
    }
    return res;
}
long long fastpow1(long long x, long long n) {
    long long res=1;
    while (n>0) {

        if(n%2==1) res=res*x;
        x*=x;
        n=n/2;
    }
    return res;
}
long long slowpow(int x, int n) {
    long long t=1;
    for(int i=1; i<=n; i++) {
        t=t*x;
    }
    return t;
}
int main() {
    freopen("BAI01.INP","r",stdin);
    freopen("BAI01.OUT","w",stdout);
    cin>>a>>b>>n>>m;

    //  cout<<fastpow1(a,n)%base1+fastpow1(b,m)%base1<<endl;
    //  cout<<slowpow(a,n)%base1+fastpow(b,m)%base1;
    cout <<fastpow(a,n)+fastpow(b,m);
    return 0;
}
