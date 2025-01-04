#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("bai03.inp");
    ofstream out("bai03.out");
    int n,a;
    inp >> n;
    vector<int> A;
    while(n--) {
        inp >> a;
        A.push_back(a);
    }
    int s=0;
    for(int i=0; i<A.size(); i++) {
        vector<int> B=A;
        B.erase(B.begin()+i);
        for(int j=0; j<B.size(); j++) {
            for(int k=j; k<B.size(); k++) {
                if(A[i]*2==B[j]+B[k]) {
                    s++;
                    j=A.size()-1;
                }
            }
        }
    }
    out << s;
    out.close();
    return 0;
}
