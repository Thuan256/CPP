#include <bits/stdc++.h>

using namespace std;

int n, m, g, s;
vector<int> servers;
vector<long long> d;
vector<vector<pair<int, int> > > adj;

void dijkstra() {
    d.assign(n, LLONG_MAX);
    for (int i = 0; i < s; ++i) {
        d[servers[i]] = 0;
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    for (int i = 0; i < s; ++i) {
        pq.push({0, servers[i]});
    }

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if (dist != d[u]) {
            continue;
        }

        for (auto [w, v] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int numTest = atoi(argv[1]);
    string test_id = to_string(numTest);
    if (numTest < 10) test_id = "0" + test_id;

    string input_file = "Test" + test_id + "/aws.inp";
    string output_file = "Test" + test_id + "/aws.out";

    freopen(input_file.c_str(), "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Calculate time
    auto start = chrono::steady_clock::now();

    cin >> n >> s >> g >> m;
    for (int i = 0; i < s; ++i) {
        int x; cin >> x;
        servers.push_back(x-1);
    }

    adj.resize(n);
    for (int i = 0; i < g; ++i) {
        int num; cin >> num;
        vector<int> group(num);
        for (int j = 0; j < num; ++j) {
            cin >> group[j];
            --group[j];
        }

        int val; cin >> val;

        for (int e1 = 0; e1 < num; ++e1) {
            for (int e2 = 0; e2 < num; ++e2) {
                if (e1 == e2) continue;
                adj[group[e1]].push_back({val, group[e2]});
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dijkstra();

    ifstream inp(output_file);

    int q; cin >> q;
    while (q--) {
        int u; cin >> u;
        --u;
        
        long long res = d[u];
        if (res == LLONG_MAX) res = -1;

        long long ans; inp >> ans;
        if (res != ans) {
            cout << ans <<'\n';
            cout << "Wrong answer on test " << numTest << ", query " << q << ": " << res << " " << ans << "\n";
            return 1;
        }
    }

    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms\n";

    return 0;
}