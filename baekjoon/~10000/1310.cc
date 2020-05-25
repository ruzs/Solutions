#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    struct pt {
        long long x, y;
        auto norm() { return x * x + y * y; }
        pt operator - (const pt & b) { return {x - b.x, y - b.y}; }
        bool operator < (pt & b) const { return x < b.x || x == b.x && y < b.y; }
    };
    auto cross = [](pt a, pt b) {
        return a.x * b.y - b.x * a.y;
    };
    auto ccw = [cross](pt a, pt b, pt c) {
        return cross(b - a, c - b);
    };

    int n;
    cin >> n;
    vector<pt> p(n);
    for(pt & i : p) cin >> i.x >> i.y;

    sort(p.begin(), p.end());
    stable_sort(p.begin() + 1, p.end(), [&](pt a, pt b){
        return ccw(p[0], a, b) > 0;
    });
    vector<pt> h;
    for(pt & i : p) {
        while(h.size() > 1 && ccw(h[h.size() - 2], h.back(), i) <= 0) h.pop_back();
        h.push_back(i);
    }

    n = h.size();
    int l = 0, r = 0;
    for(int i =0; i<n; ++i) if (h[r].x < h[i].x) r = i;

    long long ans = (h[r] - h[l]).norm();
    for(int i =0; i<n; ++i) {
        if (cross(h[(l + 1) % n] - h[l], h[r] - h[(r + 1) % n]) > 0) l = (l + 1) % n;
        else r = (r + 1) % n;
        ans = max(ans, (h[r] - h[l]).norm());
    }
    cout << ans;
}