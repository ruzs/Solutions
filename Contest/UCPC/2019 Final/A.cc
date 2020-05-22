#include <bits/stdc++.h>

using namespace std;

struct node {
    node * l = 0, * r = 0;
    long long v = 0;
    node(long long v) : v(v) {}
    node(node * l, node * r) : l(l), r(r) {
        if (l) v += l->v;
        if (r) v += r->v;
    }
};
vector<node *> st;

node * build(int l, int r) {
    if (l == r) return new node(1);
    int m = l + r >> 1;
    return new node(build(l, m), build(m + 1, r));
}

node * add(node * n, int p, int l, int r) {
    if (l == r) return new node(0);
    int m = l + r >> 1;
    if (p <= m) return new node(add(n->l, p, l, m), n->r);
    return new node(n->l, add(n->r, p, m + 1, r));
}

int kth(node * n, long long k, int l, int r) {
    if (n->v < k) return -1;
    if (l == r) return l;
    int m = l + r >> 1;
    if (n->l->v >= k) return kth(n->l, k, l, m);
    return kth(n->r, k - n->l->v, m + 1, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1), w(m + 1);
    for(int i =1; i<=n; ++i) {
        cin >> a[i];
        if (w[a[i]]) continue;
        w[a[i]] = i;
    }
    st.push_back(build(1, m));
    for(int i =n; i>=1; --i)
        st.push_back(add(st.back(), a[i], 1, m));

    vector<long long> b(m + 1);
    for(int i =1; i<=m; ++i) {
        if (w[i]) {
            b[i] = st[n - w[i]]->v;
        } else {
            b[i] = m;
        }
    }
    for(int i =1; i<=m; ++i) b[i] += b[i - 1];
    while(q--) {
        long long k; cin >> k;
        if (b[m] < k) cout << "-1 -1\n";
        else {
            auto lb = lower_bound(b.begin(), b.end(), k);
            int x = lb - b.begin();
            cout << x << ' ' << kth(st[w[x] ? n - w[x] : 0], k - *prev(lb), 1, m) << '\n';
        }
    }
}