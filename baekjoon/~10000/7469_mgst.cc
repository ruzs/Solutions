#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> st;

void build(vector<int>& a, int i, int l, int r) {
    if (l == r) return st[i].push_back(a[l]);
    int m = l + r >> 1;
    build(a, i << 1, l, m);
    build(a, i << 1 | 1, m + 1, r);
    auto & L = st[i << 1];
    auto & R = st[i << 1 | 1];
    merge(L.begin(), L.end(), R.begin(), R.end(), back_inserter(st[i]));
}
int sum(int s, int e, int x, int i, int l, int r) {
    if (e < l || r < s) return 0;
    if (s <= l && r <= e)
        return upper_bound(st[i].begin(), st[i].end(), x) - st[i].begin();
    int m = l + r >> 1;
    return sum(s, e, x, i << 1, l, m) + sum(s, e, x, i << 1 | 1, m + 1, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    st.resize(n << 2);
    for(int i =1; i<=n; ++i) cin >> a[i];
    build(a, 1, 1, n);
    while(m--) {
        int i, j, k;
        cin >> i >> j >> k;
        int lo = -1e9, hi = 1e9, md;
        while(lo < hi) {
            md = lo + hi >> 1;
            if (sum(i, j, md, 1, 1, n) < k) lo = md + 1;
            else hi = md;
        }
        cout << lo << '\n';
    }
}