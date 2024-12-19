#include <bits/stdc++.h>
using namespace std;

struct RNA {
    int c, g;
};

RNA _count(string str) {
    RNA result = {0, 0};

    for (char chr: str) {
        result.c += (chr == 'C');
        result.g += (chr == 'G');
    }

    return result;
}


int main() {
    ifstream inp("BAI1.inp");
    ofstream out("BAI1.out");

    int n, ans = 0, max_point = INT_MIN;
    string virus, vaccine;

    inp >> n >> virus;

    RNA RNA_virus = _count(virus);

    for (int i = 0; i < n; i++) {
        inp >> vaccine;

        RNA RNA_vaccine = _count(vaccine);

        int point = RNA_vaccine.c * RNA_virus.g + RNA_vaccine.g * RNA_virus.c;

        if (point > max_point) {
            ans = i;
            max_point = point;
        }
    }

    out << ans + 1 << endl;

    inp.close();
    out.close();

    return 0;
}
