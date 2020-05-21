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
        int p; cin >> p;
        if (p > 0) g[p].push_back(i);
    }

    vector<int> in(n + 1), out(n + 1);
    int ett = 0;
    function<void(int)> dfs = [&](int u) {
        in[u] = ++ett;
        for(int v : g[u]) dfs(v);
        out[u] = ett;
    };
    dfs(1);
    fenwick<int> up(n + 1), down(n + 2);
    int dir = 1;
    while(m--) {
        int o, x, w;
        cin >> o;
        if (o == 1) {
            cin >> x >> w;
            if (dir) {
                down.add(in[x], w);
                down.add(out[x] + 1, -w);
            } else {
                up.add(in[x], w);
            }
        } else if (o == 2) {
            cin >> x;
            cout << down.sum(in[x]) + up.sum(out[x]) - up.sum(in[x] - 1) << '\n';
        } else {
            dir ^= 1;
        }
    }
}