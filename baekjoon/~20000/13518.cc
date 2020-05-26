#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> w(n + 1), h(n + 1), et, in(n + 1), out(n + 1);
    vector<vector<int>> g(n + 1), p(n + 1, vector<int>(18));
    int ett = 0;
    for(int i =1; i<=n; ++i) cin >> w[i];
    for(int i =1; i<n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    function<void(int)> dfs = [&](int u) {
        in[u] = et.size();
        et.push_back(u);
        for(int v : g[u])
            if (v != p[u][0]) {
                p[v][0] = u;
                h[v] = h[u] + 1;
                dfs(v);
            }
        out[u] = et.size();
        et.push_back(u);
    };
    h[1] = 1;
    dfs(1);

    for(int j =1; j<18; ++j) for(int i =1; i<=n; ++i) p[i][j] = p[p[i][j - 1]][j - 1];
    auto lca = [&](int a, int b) {
        if (h[a] < h[b]) swap(a, b);
        for(int j =17; ~j; --j) if (h[p[a][j]] >= h[b]) a = p[a][j];
        if (a == b) return a;
        for(int j =17; ~j; --j) if (p[a][j] != p[b][j]) a = p[a][j], b = p[b][j];
        return p[a][0];
    };

    const int rt = 320;
    struct Q {
        int s, e, ca, qi;
        bool operator < (Q & b) const {
            return make_pair(s / rt, e) < make_pair(b.s / rt, b.e);
        }
    };
    int m;
    cin >> m;
    vector<Q> q(m);
    vector<int> ans(m);
    for(int i =0; i<m; ++i) {
        int s, e;
        cin >> s >> e;
        if (in[s] > in[e]) swap(s, e);
        int ca = lca(s, e);
        if (ca == s) {
            q[i] = {in[s], in[e], -1, i};
        } else {
            q[i] = {out[s], in[e], ca, i};
        }
    }
    sort(q.begin(), q.end());
    int c = 0;
    vector<int> cnt(1000005), f(n + 1);
    int l = 1, r = 0;
    auto tog = [&](int x) {
        if (f[et[x]]) {
            if (!--cnt[w[et[x]]]) c--;
        } else {
            if (!cnt[w[et[x]]]++) c++;
        }
        f[et[x]] ^= 1;
    };
    for(auto & [s, e, ca, qi] : q) {
        while(l < s) tog(l++);
        while(l > s) tog(--l);
        while(r < e) tog(++r);
        while(r > e) tog(r--);
        ans[qi] = c + (~ca && !cnt[w[ca]]);
    }
    for(int i : ans) cout << i << '\n';
}