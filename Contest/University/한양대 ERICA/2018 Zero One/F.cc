#include <bits/stdc++.h>

using namespace std;

struct disjoint_set {
    vector<int> a;
    disjoint_set(int n) { a.resize(n, -1); }

    int find(int u) {
        return a[u] < 0 ? u : a[u] = find(a[u]);
    }
    int merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return -1;
        if (a[u] > a[v]) swap(u, v);
        a[u] += a[v];
        return a[v] = u;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(string & i : a) cin >> i;
    auto enc = [m](int y, int x) { return y * m + x; };
    disjoint_set ds(n * m);
    for(int i =0; i<n; ++i) {
        for(int j =0; j<m; ++j) {
            if (a[i][j] == 'L') ds.merge(enc(i, j), enc(i, j - 1));
            else if (a[i][j] == 'U') ds.merge(enc(i, j), enc(i - 1, j));
            else if (a[i][j] == 'R') ds.merge(enc(i, j), enc(i, j + 1));
            else if (a[i][j] == 'D') ds.merge(enc(i, j), enc(i + 1, j));
        }
    }
    cout << count_if(ds.a.begin(), ds.a.end(), [](int a){return a < 0;});
}