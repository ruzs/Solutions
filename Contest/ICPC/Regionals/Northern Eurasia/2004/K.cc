#include <bits/stdc++.h>

using namespace std;

struct node {
    node * l = 0, * r = 0;
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

node * add(node * n, int x, int l, int r) {
    if (l == r) return new node(n->v + 1);
    int m = l + r >> 1;
    if (x <= m) return new node(add(n->l, x, l, m), n->r);
    else return new node(n->l, add(n->r, x, m + 1, r));
}

int kth(node * p, node * n, int k, int l, int r) {
    if (l == r) return l;
    int m = l + r >> 1;
    int left = n->l->v - p->l->v;
    if (left >= k) return kth(p->l, n->l, k, l, m);
    return kth(p->r, n->r, k - left, m + 1, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a, ord;

    for(int i =0; i<n; ++i) {
        int x; cin >> x;
        a.push_back(x);
        ord.push_back(x);
    }
    
    sort(ord.begin(), ord.end());
    ord.resize(unique(ord.begin(), ord.end()) - ord.begin());

    n = ord.size();
    st.push_back(build(0, n));
    for(int i : a) {
        int x = lower_bound(ord.begin(), ord.end(), i) - ord.begin();
        st.push_back(add(st.back(), x, 0, n));
    }

    while(m--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << ord[kth(st[i - 1], st[j], k, 0, n)] << '\n';
    }
}