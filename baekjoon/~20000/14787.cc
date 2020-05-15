#include <bits/stdc++.h>

using namespace std;

vector<int> st, sz;

void update(int k, int v, int n = 1, int l = 0, int r = 100000) {
    if (l == r) {
        st[n] = v;
        sz[n] = 1;
    } else {
        int m = l + r >> 1;
        if (k <= m) update(k, v, n << 1, l, m);
        else update(k, v, n << 1 | 1, m + 1, r);
        st[n] = st[n << 1] ^ st[n << 1 | 1];
        sz[n] = sz[n << 1] + sz[n << 1 | 1];
    }
}

int query(int s, int e, int n = 1, int l = 0, int r = 100000) {
    if (e < l || r < s) return 0;
    if (s <= l && r <= e) return st[n];
    int m = l + r >> 1;
    return query(s, e, n << 1, l, m) ^ query(s, e, n << 1 | 1, m + 1, r);
}

int kth(int k, int n = 1, int l = 0, int r = 100000) {
    if (l == r) return l;
    int m = l + r >> 1;
    if (sz[n << 1] >= k) return kth(k, n << 1, l, m);
    else return kth(k - sz[n << 1], n << 1 | 1, m + 1, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) [] {
        int n;
        cin >> n;
        st = vector<int>(400000);
        sz = vector<int>(400000);
        vector<pair<int, int>> q;
        vector<int> ord;
        for(int i =0; i<n; ++i) {
            string s;
            int v;
            cin >> s >> v;
            if (s == "insert") {
                q.push_back({1, v});
                ord.push_back(v);
            } else {
                q.push_back({0, v});
            }
        }
        sort(ord.begin(), ord.end());
        int cnt = 0;
        for(auto & [insert, v] : q) {
            if (insert) {
                auto k = lower_bound(ord.begin(), ord.end(), v);
                cnt++;
                update(k - ord.begin(), v);
                if (k == ord.begin()) *k = -1;
                else *k = *prev(k);
            } else {
                int k = kth(cnt - v + 1);
                if (cnt < v) cout << query(0, 100000) << '\n';
                else cout << query(k, 100000) << '\n';
            }
        }
    } ();
}