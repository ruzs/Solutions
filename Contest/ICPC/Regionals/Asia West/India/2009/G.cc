#include <bits/stdc++.h>

using namespace std;

int tr[100000 * 32][2], ti;

void insert(unsigned x) {
    for(int i =0, j =31; ~j; --j) {
        int & nxt = tr[i][x >> j & 1];
        i = nxt ? nxt : nxt = ++ti;
    }
}
unsigned query(unsigned x) {
    unsigned ans = 0;
    for(int i =0, j =31; ~j; --j) {
        ans <<= 1;
        if (x >> j & 1) {
            if (tr[i][0]) {
                i = tr[i][0];
                ans |= 1;
            } else i = tr[i][1];
        } else {
            if (tr[i][1]) {
                i = tr[i][1];
                ans |= 1;
            } else i = tr[i][0];
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) [] {
        unsigned n;
        cin >> n;
        memset(tr, 0, sizeof tr); ti = 0;
        insert(0);
        unsigned ps = 0, mx = 0;
        for(int i =0; i<n; ++i) {
            unsigned x; cin >> x;
            ps ^= x;
            mx = max(mx, query(ps));
            insert(ps);
        }
        cout << mx << '\n';
    } ();
}