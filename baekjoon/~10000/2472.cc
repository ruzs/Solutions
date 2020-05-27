#include <bits/stdc++.h>

using namespace std;

int st[1 << 18], N = 100005;

void update(int p, int x, int i = 1, int l = 0, int r = N) {
    if (l == r) st[i] = min(st[i], x);
    else {
        int m = l + r >> 1;
        if (p <= m) update(p, x, i << 1, l, m);
        else update(p, x, i << 1 | 1, m + 1, r);
        st[i] = min(st[i << 1], st[i << 1 | 1]);
    }
}
int query(int s, int e, int i = 1, int l = 0, int r = N) {
    if (e < l || r < s) return 1e9;
    if (s <= l && r <= e) return st[i];
    int m = l + r >> 1;
    return min(query(s, e, i << 1, l, m), query(s, e, i << 1 | 1, m + 1, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, A, B, C;
    cin >> n >> A >> B >> C >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    auto dijkstra = [&](int s, vector<int> & d) {
        priority_queue<pair<int, int>> pq;
        d.assign(n + 1, 1e9);
        d[s] = 0;
        pq.push({0, s});
        while(pq.size()) {
            auto [c, a] = pq.top(); pq.pop();
            if (-c > d[a]) continue;
            for(auto & [b, w] : g[a]) {
                int nc = -c + w;
                if (d[b] > nc) {
                    d[b] = nc;
                    pq.push({-nc, b});
                }
            }
        }
    };
    vector<int> da, db, dc;
    dijkstra(A, da);
    dijkstra(B, db);
    dijkstra(C, dc);
    
    auto ord = da;
    sort(ord.begin(), ord.end());
    ord.erase(unique(ord.begin(), ord.end()), ord.end());
    vector<tuple<int, int, int, int>> a(n);
    for(int i =1; i<=n; ++i) {
        a[i - 1] = {dc[i], lower_bound(ord.begin(), ord.end(), da[i]) - ord.begin(), db[i], i - 1};
    }
    sort(a.begin(), a.end());
    memset(st, 64, sizeof st);
    vector<int> ans(n);
    for(auto & [c, a, b, i] : a) {
        if (query(0, a) >= b) ans[i] = 1;
        update(a, b);
    }
    int q;
    cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << (ans[x - 1] ? "YES" : "NO") << '\n';
    }
}