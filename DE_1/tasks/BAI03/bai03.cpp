#include <bits/stdc++.h>

using namespace std;

map<int, bool> mapp;
vector<int> even, odd;
int n, ans, a[50006], max_ai;

void isrt(int val) {
    bool if_exist = mapp.count(val);
    if(if_exist == false)
        mapp.insert(make_pair(val, false));
    return ;
}

int cnt1[100005];

void sub1() {
    int res = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i+1; j <= n; ++j)
            if((a[i] + a[j]) % 2 == 0)
                for(int t = 1; t <= n; ++t)
                    if(a[t] == (a[i] + a[j]) / 2 && cnt1[t] == 0)
                        res++, cnt1[t] = 1;
    cout << res;
}

int dem[100005];

void sub2() {
    for(int i = 1; i <= n; ++i)
        dem[a[i]]++;
    int res = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i+1; j <= n; ++j)
            if((a[i] + a[j]) % 2 == 0)
                res += dem[(a[i] + a[j]) / 2], dem[(a[i] + a[j]) / 2] = 0;
    cout << res;
}

void subtask3() {
    sort(a + 1, a + n + 1);
    for(int i = n; i > 0; i--) {
        isrt(2 * a[i]);

        if(a[i] % 2 == 0) {
            for(int u : even)
                if(mapp.count(a[i] + u) == true && mapp.at(a[i] + u) == false)
                    ans++, mapp.at(a[i] + u) = true;
            even.push_back(a[i]);
        } else {
            for(int u : odd)
                if(mapp.count(a[i] + u) == true && mapp.at(a[i] + u) == false)
                    ans++, mapp.at(a[i] + u) = true;
            odd.push_back(a[i]);
        }
    }

    cout << ans;
}

int cnt[5005];
bool chk[5005];

void subtask4() {
    for(int i = 1; i <= n; i++)
        cnt[a[i]]++;
    for(int i = 1; i <= max_ai; i++) {
        if(cnt[i] > 1)
            chk[i] = true;
        for(int j = i + 2; j <= max_ai; j += 2)
            if(cnt[i] > 0 && cnt[j] > 0 && cnt[(i + j) / 2] > 0)
                chk[(i + j) / 2] = true;
    }

    for(int i = 1; i <= max_ai; i++)
        ans += cnt[i] * chk[i];

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("avernum.inp", "r", stdin);
    freopen("avernum.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        max_ai = max(max_ai, a[i]);
    }


    if(n <= 3000 && max_ai <= 1000000000)
        subtask3();
    else if(n <= 50000)
        subtask4();
}
