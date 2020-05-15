#include <bits/stdc++.h>

using namespace std;

int st[120000], cnt[120000];

void update(int s, int e, int x, int i = 1, int l = 0, int r = 30000) {
    if (e < l || r < s) return;
    if (s <= l && r <= e) {
        cnt[i] += x;
    } else {
        int m = l + r >> 1;
        update(s,e,x,i<<1,l,m);
        update(s,e,x,i<<1|1,m+1,r);
    }
    if (cnt[i]) st[i] = r - l + 1;
    else {
        if (l == r) st[i] = 0;
        else st[i] = st[i << 1] + st[i << 1 | 1];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> a;
    for(int i =0; i<n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.emplace_back(x1, y1, y2, 1);
        a.emplace_back(x2, y1, y2, -1);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i =0, j =0; i<=30000; ++i) {
        while (get<0>(a[j]) == i) {
            auto & [x, y1, y2, w] = a[j];
            update(y1, y2 - 1, w);
            j++;
        }
        ans += st[1];
    }
    cout << ans + st[1];
}