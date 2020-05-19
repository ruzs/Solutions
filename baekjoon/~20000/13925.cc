#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1 << 17;
int n, st[N << 1], lza[N << 1], lzb[N << 1];

void push(int i, int l, int r) {
    if (lza[i] != 1 || lzb[i] != 0) {
        st[i] = ((long long)lza[i] * st[i] + (long long)lzb[i] * (r - l + 1)) % mod;
        if (l != r) {
            lzb[i << 1] = ((long long)lza[i] * lzb[i << 1] + lzb[i]) % mod;
            lza[i << 1] = ((long long)lza[i] * lza[i << 1]) % mod;
            lzb[i<<1|1] = ((long long)lza[i] * lzb[i<<1|1] + lzb[i]) % mod;
            lza[i<<1|1] = ((long long)lza[i] * lza[i<<1|1]) % mod;
        }
        lza[i] = 1;
        lzb[i] = 0;
    }
}
void build(const vector<int> & a, int i = 1, int l = 1, int r = n) {
    lza[i] = 1; lzb[i] = 0;
    if (l == r) {
        st[i] = a[l] % mod;
    } else {
        int m = l + r >> 1;
        build(a, i << 1, l, m);
        build(a, i << 1 | 1, m + 1, r);
        st[i] = (st[i << 1] + st[i << 1 | 1]) % mod;
    }
}
void update(int s, int e, int a, int b, int i = 1, int l = 1, int r = n) {
    push(i, l, r);
    if (e < l || r < s) return;
    if (s <= l && r <= e) {
        lza[i] = ((long long)lza[i] * a) % mod;
        lzb[i] = ((long long)lzb[i] * a) % mod;
        lzb[i] = (lzb[i] + b) % mod;
        push(i, l, r);
    } else {
        int m = l + r >> 1;
        update(s, e, a, b, i << 1, l, m);
        update(s, e, a, b, i << 1 | 1, m + 1, r);
        st[i] = (st[i << 1] + st[i << 1 | 1]) % mod;
    }
}
int sum(int s, int e, int i = 1, int l = 1, int r = n) {
    push(i, l, r);
    if (e < l || r < s) return 0;
    if (s <= l && r <= e) return st[i];
    int m = l + r >> 1;
    return (sum(s, e, i << 1, l, m) + sum(s, e, i << 1 | 1, m + 1, r)) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> a(N);
    for(int i =1; i<=n; ++i) cin >> a[i];
    build(a);
    int m;
    cin >> m;
    while(m--) {
        int order, x, y, v;
        cin >> order;
        if (order == 4) {
            cin >> x >> y;
            cout << sum(x, y) << '\n';
        } else {
            cin >> x >> y >> v;
            if (order == 1) {
                update(x, y, 1, v);
            } else if (order == 2) {
                update(x, y, v, 0);
            } else {
                update(x, y, 0, v);
            }
        }
    }
}