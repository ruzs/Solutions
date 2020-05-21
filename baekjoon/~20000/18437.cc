#include <bits/stdc++.h>

using namespace std;

int sn = 1;
vector<int> st, lz;

void push(int i, int l, int r) {
    if (~lz[i]) {
        st[i] = (r - l + 1) * lz[i];
        if (l != r) lz[i << 1] = lz[i << 1 | 1] = lz[i];
        lz[i] = -1;
    }
}
void update(int s, int e, int x, int i = 1, int l = 1, int r = sn) {
    push(i, l, r);
    if (e < l || r < s) return;
    if (s <= l && r <= e) {
        lz[i] = x;
        push(i, l, r);
    } else {
        int m = l + r >> 1;
        update(s, e, x, i << 1, l, m);
        update(s, e, x, i << 1 | 1, m + 1, r);
        st[i] = st[i << 1] + st[i << 1 | 1];
    }
}
int sum(int s, int e, int i = 1, int l = 1, int r = sn) {
    push(i, l, r);
    if (e < l || r < s) return 0;
    if (s <= l && r <= e) return st[i];
    int m = l + r >> 1;
    return sum(s, e, i << 1, l, m) + sum(s, e, i << 1 | 1, m + 1, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(sn < n) sn <<= 1;
    st.resize(sn << 1);
    lz.resize(sn << 1, -1);
    vector<vector<int>> g(n + 1);
    for(int i =1; i<=n; ++i) {
        int p; cin >> p;
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
    
    int m;
    cin >> m;
    update(1, n, 1);
    while(m--) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            if (in[y] ^ out[y]) update(in[y] + 1, out[y], 1);
        } else if (x == 2) {
            if (in[y] ^ out[y]) update(in[y] + 1, out[y], 0);
        } else {
            if (in[y] ^ out[y]) cout << sum(in[y] + 1, out[y]) << '\n';
            else cout << 0 << '\n';
        }
    }
}