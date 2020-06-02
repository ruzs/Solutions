#include <bits/stdc++.h>

using namespace std;

struct node {
    node *l = 0, *r = 0;
    int v = 0;
    node(int v) : v(v) {}
    node(node * l, node * r) : l(l), r(r) {
        if (l) v += l->v;
        if (r) v += r->v;
    }
};

vector<node *> st;

node * build(int l, int r) {
    if (l == r) return new node(0);
    int m = l + r >> 1;
    return new node(build(l, m), build(m + 1, r));
}

int sum(node * n, int l, int r, int s, int e) {
    if (e < l || r < s) return 0;
    if (s <= l && r <= e) return n->v;
    int m = l + r >> 1;
    return sum(n->l, l, m, s, e) + sum(n->r, m + 1, r, s, e);
}

node * add(node * n, int l, int r, int pos, int val) {
    if (l == r) return new node(n->v + val);
    int m = l + r >> 1;
    if (pos <= m)
        return new node(add(n->l, l, m, pos, val), n->r);
    else
        return new node(n->l, add(n->r, m + 1, r, pos, val));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> p;
        for(int i =0; i<n; ++i) {
            int x, y;
            cin >> x >> y;
            p.emplace_back(x, y);
        }
        sort(p.begin(), p.end());

        st.clear();
        st.push_back(build(0, 100005));
        for(auto & [x, y] : p) {
            while(st.size() < x + 1) st.push_back(st.back());
            st[x] = add(st[x], 0, 100005, y, 1);
        }
        while(st.size() < 100005) st.push_back(st.back());
        int ans = 0;
        while(q--) {
            int x1, x2, y1, y2;
            cin >> x1 >> x2 >> y1 >> y2;
            ans += sum(st[x2], 0, 100005, y1, y2) - sum(st[x1 - 1], 0, 100005, y1, y2);
        }
        cout << ans << '\n';
    }
}