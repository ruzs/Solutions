#include <bits/stdc++.h>

using namespace std;

struct rmq {
    int st[1 << 20];
    int n = 1 << 19;
    rmq() { memset(st, 128, sizeof st); }
    void update(int p, int x) {
        p += n;
        st[p] = max(st[p], x);
        while(p >>= 1) st[p] = max(st[p << 1], st[p << 1 | 1]);
    }
    int query(int s, int e) {
        int ret = max(st[s += n], st[e += n]);
        while(s <= e) {
            if (s % 2 == 1) ret = max(ret, st[s++]);
            if (e % 2 == 0) ret = max(ret, st[e--]);
            s >>= 1; e >>= 1;
        }
        return ret;
    }
} upper, lower;

struct market {
    int L, M;
    bool operator < (market & b) const {
        return L < b.L;
    }
};
vector<market> mkt[1 << 19];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, U, D, S;
    cin >> N >> U >> D >> S;

    for(int i =1; i<=N; ++i) {
        int t, l, m;
        cin >> t >> l >> m;
        mkt[t].push_back({l, m});
    }

    upper.update(S, S * D);
    lower.update(S, -S * U);
    int ans = 0;
    for(int day =1; day<=500000; ++day) {
        vector<market> & a = mkt[day];
        if (a.empty()) continue;

        sort(a.begin(), a.end());
        int n = a.size();

        vector<int> d(n), dl(n), dr(n);
        for(int i =0; i<n; ++i) {
            d[i] = max(upper.query(1, a[i].L - 1) - a[i].L * D, lower.query(a[i].L + 1, 500001) + a[i].L * U) + a[i].M;
        }
        dl[0] = d[0];
        dr[n-1] = d[n-1];
        for(int i =1; i<n; ++i)
            dl[i] = max(d[i], dl[i - 1] - (a[i].L - a[i - 1].L) * D + a[i].M);
        for(int i =n-2; i>=0; --i)
            dr[i] = max(d[i], dr[i + 1] - (a[i + 1].L - a[i].L) * U + a[i].M);
        for(int i =0; i<n; ++i) {
            ans = max(ans, dl[i] - abs(a[i].L - S) * (a[i].L > S ? U : D));
            ans = max(ans, dr[i] - abs(a[i].L - S) * (a[i].L > S ? U : D));
            upper.update(a[i].L, max(dl[i] + a[i].L * D, dr[i] + a[i].L * D));
            lower.update(a[i].L, max(dl[i] - a[i].L * U, dr[i] - a[i].L * U));
        }
    }
    cout << ans;
}