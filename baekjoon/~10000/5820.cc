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
        map<int, int> mp = {{0, 0}}, q;
        function<void(int, int, int, int)>
        dfs = [&](int u, int p, int l, int d) {
            if (l > k) return;
            if (mp.count(k - l)) ans = min(ans, mp[k - l] + d);
            if (q.count(l)) q[l] = min(q[l], d);
            else q[l] = d;
            for(auto & [v, w] : g[u]) {
                if (v == p || exc[v]) continue;
                dfs(v, u, l + w, d + 1);
            }
        };
        for(auto & [v, w] : g[ct]) {
            if (exc[v]) continue;
            dfs(v, ct, w, 1);
            for(auto & i : q) {
                if (mp.count(i.first)) mp[i.first] = min(mp[i.first], i.second);
                else mp[i.first] = i.second;
            }
            q.clear();
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