#include <bits/stdc++.h>

using namespace std;

int N = 1 << 18;
struct segment_tree {
    vector<int> st, lz;
    segment_tree(int sz) {
        st.resize(N << 1);
        lz.resize(N << 1, -1);
    }

    void push(int i, int l, int r) {
        if (~lz[i]) {
            st[i] = max(st[i], lz[i]);
            if (l != r) {
                lz[i << 1] = max(lz[i << 1], lz[i]);
                lz[i << 1 | 1] = max(lz[i << 1 | 1], lz[i]);
            }
            lz[i] = -1;
        }
    }
    void update(int s, int e, int x, int i = 1, int l = 1, int r = N) {
        push(i, l, r);
        if (e < l || r < s) return;
        if (s <= l && r <= e) {
            lz[i] = max(lz[i], x);
            push(i, l, r);
        } else {
            int m = l + r >> 1;
            update(s, e, x, i << 1, l, m);
            update(s, e, x, i << 1 | 1, m + 1, r);
        }
    }
    int find(int p, int i = 1, int l = 1, int r = N) {
        push(i, l, r);
        if (l == r) return st[i];
        int m = l + r >> 1;
        if (p <= m) return find(p, i << 1, l, m);
        else return find(p, i << 1 | 1, m + 1, r);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i=2; i<=n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    vector<int> in(n + 1), out(n + 1);
    int ett = 0;
    function<void(int)> dfs = [&](int u) {
        in[u] = ++ett;
        for(int v : g[u]) dfs(v);
        out[u] = ett;
    };
    dfs(1);

    segment_tree st(n);
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        int xn = st.find(in[x]);
        int yn = st.find(in[y]);
        cout << (xn == yn ? "YES\n" : "NO\n");
        if (z) {
            if (xn == yn) {
                st.update(in[x], out[x], in[x]);
            } else {
                st.update(in[y], out[y], in[y]);
            }
        }
    }
}