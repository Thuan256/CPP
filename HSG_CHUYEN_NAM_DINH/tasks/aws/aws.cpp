#include <bits/stdc++.h>

using namespace std;

int n, m, g, s;
vector<int> servers;
vector<long long> d;
vector<vector<pair<int, int> > > adj;

void dijkstra() {
    d.assign(n+g, LLONG_MAX);
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> s >> g >> m;

    servers.resize(s);
    for (int i = 0; i < s; ++i) {
        cin >> servers[i];
        --servers[i];
    }

    adj.resize(n+g);
    for (int i = 0; i < g; ++i) {
        int num; cin >> num;
        vector<int> group(num);
        for (int j = 0; j < num; ++j) {
            cin >> group[j];
            --group[j];
        }

        int val; cin >> val;

        for (int j = 0; j < num; ++j) {
            adj[group[j]].push_back({val, n+i});
            adj[n+i].push_back({0, group[j]});
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dijkstra();

    int q; cin >> q;
    while (q--) {
        int u; cin >> u;
        --u;
        cout << (d[u] == LLONG_MAX ? -1 : d[u]) << '\n';
    }

    return 0;
}

// 7 1 2 2
// 1  
// 3 1 2 3 2
// 4 4 5 6 7 3
// 3 4 4
// 1 5 10 
// 1
// 5