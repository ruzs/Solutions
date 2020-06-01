#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, b, s, r;
    cin >> n >> b >> s >> r;
    vector<vector<pair<int, int>>> g1(n + 1), g2(n + 1);

    for(int i =0; i<r; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g1[u].emplace_back(v, w);
        g2[v].emplace_back(u, w);
    }
    vector<int> d1(n + 1, 1e9), d2(n + 1, 1e9);
    auto dijkstra = [&](int src, auto & g, auto & dist) {
        priority_queue<pair<int, int>> pq;
        pq.emplace(0, b + 1);
        dist[b + 1] = 0;
        while(pq.size()) {
            auto [c, u] = pq.top(); pq.pop();
            if (-c > dist[u]) continue;
            for(auto & [v, w] : g[u]) {
                int nc = -c + w;
                if (dist[v] > nc) {
                    dist[v] = nc;
                    pq.emplace(-nc, v);
                }
            }
        }
    };
    dijkstra(b + 1, g1, d1);
    dijkstra(b + 1, g2, d2);
    vector<long long> a = {0}, ps;
    for(int i =1; i<=b; ++i) a.push_back(d1[i] + d2[i]);
    sort(a.begin(), a.end());
    partial_sum(a.begin(), a.end(), back_inserter(ps));
    vector<long long> d_pre(b + 1, 1e18), d_cur(b + 1);
    d_pre[0] = 0;
    function<void(int, int, int, int)>
    dnc = [&](int l, int r, int optl, int optr) {
        if (l > r) return;
        int m = l + r >> 1;
        pair<long long, int> best{1e18, -1};
        for(int k =optl; k<=min(m, optr); ++k) {
            best = min(best, {d_pre[k - 1] + (ps[m] - ps[k - 1]) * (m - k), k});
        }
        d_cur[m] = best.first;
        int optm = best.second;
        dnc(l, m - 1, optl, optm);
        dnc(m + 1, r, optm, optr);
    };
    for(int i =0; i<s; ++i) {
        dnc(1, b, 1, b);
        swap(d_pre, d_cur);
    }
    cout << d_pre[b];
}