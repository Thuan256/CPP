#include <bits/stdc++.h>
using namespace std;

struct task {
    int a, b, c, diff;
};

task tasks[200001];

bool compare(task x, task y) {
    return (x.diff < y.diff);
}

int main() {
    ifstream inp("BAI3.inp");
    ofstream out("BAI3.out");

    int m, n, i;
    inp >> m >> n;

    for (i = 1; i <= m + n; i++) {
        inp >> tasks[i].a >> tasks[i].b >> tasks[i].c;

        if (tasks[i].c == 0)
            tasks[i].diff = tasks[i].a - tasks[i].b;
        else if (tasks[i].c == 1)
            tasks[i].diff = INT_MIN;
        else
            tasks[i].diff = INT_MAX;
    }
    sort(tasks + 1, tasks + m + n + 1, compare);

    long long ans = 0;
    for (i = 1; i <= m; i++) ans += tasks[i].a;

    for (i = m + 1; i <= m + n; i++) ans += tasks[i].b;

    out << ans;

    inp.close();
    out.close();

    return 0;
}
