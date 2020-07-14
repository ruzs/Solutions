#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> g(n);
    for(int i =1; i<n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<int> sz(n);
    vector<int> exc(n);
    vector<int> md(1000001, 1e9);
    queue<int> q;
    int ans = 1e9;
    function<int(int, int)> tree_size = [&](int u, int p) {
        sz[u] = 1;
        for(auto & [v, w] : g[u]) {
            if (v == p || exc[v]) continue;
            sz[u] += tree_size(v, u);
        }
        return sz[u];
    };
    function<int(int, int, int)> centroid = [&](int u, int p, int lim) {
        for(auto & [v, w] : g[u]) {
            if (v == p || exc[v]) continue;
            if (sz[v] > lim) return centroid(v, u, lim);
        }
        return u;
    };
    function<void(int)> dnc = [&](int u) {
        int ts = tree_size(u, -1);
        int ct = centroid(u, -1, ts / 2);
        exc[ct] = 1;
        while(q.size()) md[q.front()] = 1e9, q.pop();
        md[0] = 0;
        function<void(int, int, int, int)>
        compute = [&](int u, int p, int l, int d) {
            if (l > k) return;
            if (md[k - l] < 1e9) ans = min(ans, md[k - l] + d);
            for(auto & [v, w] : g[u]) {
                if (v == p || exc[v]) continue;
                compute(v, u, l + w, d + 1);
            }
        },
        update = [&](int u, int p, int l, int d) {
            if (l > k) return;
            md[l] = min(md[l], d);
            q.push(l);
            for(auto & [v, w] : g[u]) {
                if (v == p || exc[v]) continue;
                update(v, u, l + w, d + 1);
            }
        };
        for(auto & [v, w] : g[ct]) {
            if (exc[v]) continue;
            compute(v, ct, w, 1);
            update(v, ct, w, 1);
        }
        for(auto & [v, w] : g[ct]) {
            if (exc[v]) continue;
            dnc(v);
        }
    };
    dnc(0);
    if (ans < 1e9) cout << ans;
    else cout << -1;
}