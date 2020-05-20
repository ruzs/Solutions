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
    vector<array<int, 18>> p(n + 5);
    vector<vector<int>> g(n + 5);
    for(int i =2; i<=n; ++i) {
        cin >> p[i][0];
        g[p[i][0]].push_back(i);
    }
    for(int j =1; j<18; ++j) for(int i =1; i<=n; ++i)
        p[i][j] = p[p[i][j - 1]][j - 1];
    vector<int> et(n + 5), sz(n + 5), h(n + 5);
    int ett = 0;
    function<void(int)> dfs = [&](int u) {
        et[u] = ++ett;
        for(int v : g[u]) {
            if (v != p[u][0]) {
                h[v] = h[u] + 1;
                dfs(v);
            }
        }
        sz[u] = ett - et[u] + 1;
    };
    h[1] = 1;
    dfs(1);
    auto lca = [&](int a, int b) {
        if (h[a] < h[b]) swap(a, b);
        for(int j =17; j>=0; --j) {
            if (h[p[a][j]] >= h[b]) a = p[a][j];
        }
        if (a == b) return a;
        for(int j =17; j>=0; --j) {
            if (p[a][j] != p[b][j]) {
                a = p[a][j];
                b = p[b][j];
            }
        }
        return p[a][0];
    };
    fenwick<int> fw(n + 5);
    int nc = 0;
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        int xx = fw.sum(et[x]);
        int yy = fw.sum(et[y]);
        int zz = fw.sum(et[lca(x, y)]);
        cout << (xx == zz && zz == yy ? "YES\n" : "NO\n");
        if (z) {
            if (xx == zz && zz == yy) {
                if (!p[x][0] || xx != fw.sum(et[p[x][0]])) continue;
                fw.add(et[x], 1);
                fw.add(et[x] + sz[x], -1);
            } else {
                if (!p[y][0] || yy != fw.sum(et[p[y][0]])) continue;
                fw.add(et[y], 1);
                fw.add(et[y] + sz[y], -1);
            }
        }
    }
}