#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 1e9 + 7;
ll dp[102][10];


void generate_dp() {

    for (int d = 0; d <= 9; d++) dp[1][d] = 1;

    for (int pos = 2; pos <= 100; pos++) {
        for (int last = 0; last <= 9; last++) {
            for (int d = last; d <= 9; d++) {
                dp[pos][d] = (dp[pos][d] + dp[pos - 1][d]) % mod;
            }
        }
    }
}

ll count_to(string limit) {
    string::size_type n = limit.length();
    ll total = 0;

    if (n == 1) return stoi(limit);

    for (string::size_type len = 1; len < n; len++) {

        for (int d = 1; d <= 9; d++) {
            total = (total + dp[len][d]) % mod;
        }
    }

    signed prev_d = 0;

    for (string::size_type i = 0; i < n; i++) {
        signed cur_d = limit[i] - '0';

        for (signed lower_d = (i == 0 ? 1 : prev_d); lower_d < cur_d; lower_d++) {
            total = (total + dp[n - 1][lower_d]) % mod;
        }

        prev_d = cur_d;
    }

    return total;
}

ll cal_ans(string& a, string& b) {

    string a_minus_1 = a;
    string b_plus_1 = b;

    for (int i = a_minus_1.length() - 1; i >= 0; i--) {
        if (a_minus_1[i] > '0') {
            a_minus_1[i]--;
            break;
        } else {
            a_minus_1[i] = '9';
        }
    }

    for (int i = b_plus_1.length() - 1; i >= 0; i--) {
        if (b_plus_1[i] < '9') {
            b_plus_1[i]++;
            break;
        } else {
            b_plus_1[i] = '0';
        }
    }

    if (a_minus_1[0] == '0'  && a_minus_1.length() > 1) a_minus_1.erase(0, 1);
    if (b_plus_1[0] == '0') b_plus_1 = '1' + b_plus_1;

    ll ans_b = count_to(b_plus_1);
    ll ans_a = a == "1" ? 0 : count_to(a_minus_1);

    cout << "ans_b: " << ans_b << ", ans_a: " << ans_a << endl;
    cout << "a_minus_1: " << a_minus_1 << ", b_plus_1: " << b_plus_1 << endl;


    return (ans_b - ans_a + mod) % mod;
}

void print_dp() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j <= 9; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    ifstream inp("PLEASANT.inp");
    ofstream out("PLEASANT.out");

    string a,b;

    getline(inp, a);
    getline(inp, b);

//    cout << a << " " << b << endl;

    inp.close();

    generate_dp();
    print_dp();

    out << cal_ans(a, b);
    out.close();
    return 0;
}

