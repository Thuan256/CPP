#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("BSET.INP");
    ofstream out("BSET.OUT");
    int a,b;
    inp >> a >> b;
    vector<int> x;
    vector<int> y;

    while(a--) {
        int num;
        inp >> num;
        x.push_back(num);
    }
    while(b--) {
        int num1;
        inp >> num1;
        y.push_back(num1);
    }
    unordered_set<int> A(x.begin(),x.end());
    unordered_set<int> B(y.begin(),y.end());
    int k=0;
    for(auto i: A) {
        for(auto j:B) {
            if(i==j)
                k++;
        }
    }
    out << A.size() + B.size() - k << " " << k;
    out.close();
    return 0;
}
