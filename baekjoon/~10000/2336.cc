#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 19;
int st[N << 1];
void update(int p, int x, int i = 1, int l = 1, int r = N-1) {
    if (l == r) st[i] = x;
    else {
        int m = l + r >> 1;
        if (p <= m) update(p, x, i << 1, l, m);
        else update(p, x, i << 1 | 1, m + 1, r);
        st[i] = min(st[i << 1], st[i << 1 | 1]);
    }
}
int query(int s, int e, int i = 1, int l = 1, int r = N-1) {
    if (e < l || r < s) return 1e9;
    if (s <= l && r <= e) return st[i];
    int m = l + r >> 1;
    return min(query(s, e, i << 1, l, m), query(s, e, i << 1 | 1, m + 1, r));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    struct rank {
        int x, y, z;
        bool operator < (rank & b) const {
            return z < b.z;
        }
    };
    vector<rank> a(n);
    for(int i =1; i<=n; ++i) {
        int x; cin >> x;
        a[x - 1].x = i;
    }
    for(int i =1; i<=n; ++i) {
        int x; cin >> x;
        a[x - 1].y = i;
    }
    for(int i =1; i<=n; ++i) {
        int x; cin >> x;
        a[x - 1].z = i;
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    memset(st, 64, sizeof st);
    for(rank & i : a) {
        if (query(1, i.x) > i.y) cnt++;
        update(i.x, i.y);
    }
    cout << cnt;
}