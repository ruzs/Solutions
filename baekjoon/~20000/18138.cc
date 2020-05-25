#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int & i : a) cin >> i;
    for(int & i : b) cin >> i;
    vector<vector<int>> g(n);
    for(int i =0; i<n; ++i) {
        for(int j =0; j<m; ++j) {
            if (a[i] <= 2 * b[j] && 3 * a[i] >= 4 * b[j]) g[i].push_back(j);
            if (a[i] <= b[j] && 5 * a[i] >= 4 * b[j]) g[i].push_back(j);
        }
    }

    vector<int> visited(n), mch(m, -1);
    function<bool(int)> bimat = [&](int u) {
        visited[u] = 1;
        for(int v : g[u]) {
            if (mch[v] < 0 || !visited[mch[v]] && bimat(mch[v])) {
                mch[v] = u;
                return true;
            }
        }
        return false;
    };
    int cnt = 0;
    for(int i =0; i<n; ++i) {
        if (visited.assign(n, 0), bimat(i)) cnt++;
    }
    cout << cnt;
}