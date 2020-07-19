#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i =1; i<=n; ++i) {
        int a, k;
        cin >> a >> k;
        g[i].push_back({a, k});
        cin >> a >> k;
        g[i].push_back({a, k});
    }
    long long ans = 1e6, j = 1e6;
    auto pos = [&](int x) {
        vector<int> mat(2 * n + 1, 0), use(n + 1, 0), lv(n + 1);
        auto bfs = [&]() {
            queue<int> q;
            for(int i =1; i<=n; ++i) {
                if (!use[i]) lv[i] = 0, q.push(i);
                else lv[i] = -1;
            }
            while(q.size()) {
                int u = q.front(); q.pop();
                for(auto & [v, w] : g[u])
                    if (mat[v] && lv[mat[v]] == -1)
                        lv[mat[v]] = lv[u] + 1,
                        q.push(mat[v]);
            }
        };
        function<bool(int)> bimatch = [&](int u) {
            for(auto & [v, w] : g[u]) {
                if (w > x) continue;
                if (!mat[v] || lv[u] < lv[mat[v]] && bimatch(mat[v])) {
                    use[u] = 1;
                    mat[v] = u;
                    return 1;
                }
            }
            return 0;
        };
        int ans = 0, fl;
        do {
            bfs();
            fl = 0;
            for(int i =1; i<=n; ++i)
                if (!use[i] && bimatch(i)) fl++;
            ans += fl;
        } while(fl);
        return ans == n;
    };
    while(j /= 2) while(pos(ans - j)) ans -= j;
    if (pos(ans)) cout << ans;
    else cout << -1;
}