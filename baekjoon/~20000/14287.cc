#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct fenwick {
    vector<T> a;
    fenwick(int n) { a.resize(n); }

    void add(int p, T x) {
        do a[p] += x;
        while ((p += p & -p) < a.size());
    }
    T sum(int p) {
        T r{};
        do r += a[p];
        while (p -= p & -p);
        return r;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i =1; i<=n; ++i) {
        int p;
        cin >> p;
        if (p > 0) g[p].push_back(i);
    }
    vector<int> et(n + 1), sz(n + 1);
    int ett = 0;
    function<void(int)> dfs = [&](int u) {
        et[u] = ++ett;
        for(int v : g[u]) {
            if (!et[v]) dfs(v);
        }
        sz[u] = ett - et[u];
    };
    dfs(1);
    debug(et);
    debug(sz);
    fenwick<int> fw(n + 1);
    while(m--) {
        int o, x, w;
        cin >> o;
        if (o == 1) {
            cin >> x >> w;
            fw.add(et[x], w);
        } else {
            cin >> x;
            cout << fw.sum(et[x] + sz[x]) - fw.sum(et[x] - 1) << '\n';
        }
    }
}