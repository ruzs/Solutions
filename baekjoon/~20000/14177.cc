#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> c(n + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> c[i][j];
    for (int i = i; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) c[i][j] += c[i][j - 1];
    for (int j = 1; j <= n; ++j)
        for (int i = j - 1; i > 0; --i) c[i][j] += c[i + 1][j];
    vector<long long> d_pre(n + 1, 1e18), d_cur(n + 1);
    d_pre[0] = 0;
    function<void(int, int, int, int)> dnc = [&](int l, int r, int optl,
                                                 int optr) {
        if (l > r)
            return;
        int m = l + r >> 1;
        pair<long long, int> best{1e18, -1};
        for (int k = optl; k <= min(m, optr); ++k) {
            best = min(best, {d_pre[k - 1] + c[k][m], k});
        }
        d_cur[m] = best.first;
        int optm = best.second;
        dnc(l, m - 1, optl, optm);
        dnc(m + 1, r, optm, optr);
    };
    for (int i = 0; i < m; ++i) {
        dnc(1, n, 1, n);
        swap(d_cur, d_pre);
    }
    cout << d_pre[n];
}