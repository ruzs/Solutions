#include <bits/stdc++.h>

using namespace std;

int tr[31 * 200000][2], ti, sz[31 * 200000];

void insert(int x) {
    for(int i =0, j =30; ~j; --j) {
        int & nxt = tr[i][x >> j & 1];
        i = nxt ? nxt : nxt = ++ti;
        sz[i]++;
    }
}
void erase(int x) {
    for(int i =0, j =30; ~j; --j) {
        i = tr[i][x >> j & 1];
        sz[i]--;
    }
}
int query(int x) {
    int ans = 0;
    for(int i =0, j =30; ~j; --j) {
        ans <<= 1;
        if (x >> j & 1) {
            if (sz[tr[i][0]]) {
                i = tr[i][0];
                ans |= 1;
            } else i = tr[i][1];
        } else {
            if (sz[tr[i][1]]) {
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

    int n;
    cin >> n;
    insert(0);
    for(int i =0; i<n; ++i) {
        int cmd, x;
        cin >> cmd >> x;
        if (cmd == 1) insert(x);
        else if (cmd == 2) erase(x);
        else cout << query(x) << '\n';
    }
}