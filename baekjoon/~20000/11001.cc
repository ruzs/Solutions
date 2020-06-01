#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<long long> t(n + 1), v(n + 1);
    for(int i =1; i<=n; ++i) cin >> t[i];
    for(int i =1; i<=n; ++i) cin >> v[i];
    long long ans = 0;
    function<void(int, int, int, int)>
    dnc = [&](int l, int r, int optl, int optr) {
        if (l > r) return;
        int m = l + r >> 1;
        pair<long long, int> best{-1e18, -1};
        for(int k =optl; k<=min(m, optr); ++k) {
            if (m - k > d) continue;
            best = max(best, {(m - k) * t[m] + v[k], k});
        }
        ans = max(ans, best.first);
        int opt = best.second;
        dnc(l, m - 1, optl, opt);
        dnc(m + 1, r, opt, optr);
    };
    dnc(1, n, 1, n);
    cout << ans;
}