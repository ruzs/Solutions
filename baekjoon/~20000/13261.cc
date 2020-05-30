#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, g;
    cin >> l >> g;
    vector<long long> c(l + 1);
    for(int i =1; i<=l; ++i) {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    vector<long long> d_pre(l + 1, 1e18), d_cur(l + 1);
    d_pre[0] = 0;
    function<void(int, int, int, int)>
    dnc = [&](int l, int r, int optl, int optr) {
        if (l > r) return;
        int m = l + r >> 1;
        pair<long long, int> best{1e18, -1};
        for(int k = optl; k<=min(m - 1, optr); ++k) {
            best = min(best, {d_pre[k] + (m - k) * (c[m] - c[k]), k});
        }
        d_cur[m] = best.first;
        int opt  = best.second;
        dnc(l, m - 1, optl, opt);
        dnc(m + 1, r, opt, optr);
    };
    for(int j =0; j<g; ++j) {
        dnc(1, l, 0, l - 1);
        swap(d_pre, d_cur);
    }
    cout << d_pre[l];
}