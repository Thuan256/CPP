#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d,i;
    cin>>n;
    for (int i=1;i<=n;i++){
        if (i%3==0|i%5==0)
            d+=1;
    }
    cout<<d;
    return 0;
}
