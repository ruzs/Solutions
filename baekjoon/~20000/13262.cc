#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i =1; i<=n; ++i) cin >> a[i];
    vector<vector<int>> c(n + 1, vector<int>(n + 1));
    for(int i =1; i<=n; ++i) {
        for(int j =i; j<=n; ++j) {
            c[i][j] = c[i][j - 1] | a[j];
        }
    }
    vector<long long> d_pre(n + 1), d_cur(n + 1);
    function<void(int, int, int, int)>
    dnc = [&](int l, int r, int optl, int optr) {
        if (l > r) return;
        int m = l + r >> 1;
        pair<long long, int> best{-1, -1};
        for(int k =optl; k <= min(m, optr); ++k) {
            best = max(best, {d_pre[k - 1] + c[k][m], k});
        }
        d_cur[m] = best.first;
        int optm = best.second;
        dnc(l, m - 1, optl, optm);
        dnc(m + 1, r, optm, optr);
    };
    for(int i =0; i<k; ++i) {
        dnc(1, n, 1, n);
        swap(d_pre, d_cur);
    }
    cout << d_pre[n];
}