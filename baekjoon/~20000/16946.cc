#include <bits/stdc++.h>

using namespace std;

struct disjoint_set {
    vector<int> a;
    disjoint_set(int n) { a.resize(n, -1); }

    inline int find(int u) {
        return a[u] < 0 ? u : a[u] = find(a[u]);
    }
    int size(int u) { return -a[find(u)]; }
    inline int merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return -1;
        if (a[u] > a[v]) swap(u, v);
        a[u] += a[v];
        return a[v] = u;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(string & i : g) cin >> i;
    auto enc = [m](int y, int x) { return y * m + x; };
    disjoint_set ds(n * m);
    for(int i =0; i<n; ++i) for(int j =0; j<m; ++j)
        if (g[i][j] == '0') {
            if (i && g[i - 1][j] == '0') ds.merge(enc(i, j), enc(i - 1, j));
            if (j && g[i][j - 1] == '0') ds.merge(enc(i, j), enc(i, j - 1));
        }
    for(int i =0; i<n; ++i) {
        for(int j =0; j<m; ++j)
            if (g[i][j] == '1') {
                int cnt = 1;
                set<int> s;
                if (i && g[i - 1][j] == '0' && !s.count(ds.find(enc(i - 1, j)))) {
                    cnt += ds.size(enc(i - 1, j));
                    s.insert(ds.find(enc(i - 1, j)));
                }
                if (j && g[i][j - 1] == '0' && !s.count(ds.find(enc(i, j - 1)))) {
                    cnt += ds.size(enc(i, j - 1));
                    s.insert(ds.find(enc(i, j - 1)));
                }
                if (i + 1 < n && g[i + 1][j] == '0' && !s.count(ds.find(enc(i + 1, j)))) {
                    cnt += ds.size(enc(i + 1, j));
                    s.insert(ds.find(enc(i + 1, j)));
                }
                if (j + 1 < m && g[i][j + 1] == '0' && !s.count(ds.find(enc(i, j + 1)))) {
                    cnt += ds.size(enc(i, j + 1));
                    s.insert(ds.find(enc(i, j + 1)));
                }
                cout << cnt % 10;
            } else cout << 0;
        cout << '\n';
    }
}