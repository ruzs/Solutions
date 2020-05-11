#include <bits/stdc++.h>

using namespace std;

struct st {
    long long ts, ls, rs, ms;
    void uni(st & l, st & r) {
        ts = l.ts + r.ts;
        ls = max(l.ls, l.ts + r.ls);
        rs = max(r.rs, r.ts + l.rs);
        ms = max({l.rs + r.ls, l.ms, r.ms, l.ts + r.ts});
    }
} sg[6000];

int n, x[3000];
struct {int x, y, w;} a[3000];
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i =0; i<n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].w;
        x[i] = a[i].x;
    }
    int m = 1;
    while(m < n) m <<= 1;
    sort(x, x + n);
    sort(a, a + n, [](auto a, auto b){return a.y < b.y;});
    for(int i =0; i<n; ++i) a[i].x = lower_bound(x, x + n, a[i].x) - x;
    for(int i =0; i<n; ++i) {
        if (i && a[i - 1].y == a[i].y) continue;
        memset(sg, 0, sizeof sg);
        for(int j =i; j<n; ++j) {
            int p = a[j].x + m;
            if (p >= n + n) p -= n;
            sg[p].ms = sg[p].rs = sg[p].ls = sg[p].ts += a[j].w;
            while(p>>=1) sg[p].uni(sg[p<<1], sg[p<<1|1]);
            if (j == n - 1 || a[j].y != a[j + 1].y) ans = max(ans, sg[1].ms);
        }
    }
    cout << ans;
}