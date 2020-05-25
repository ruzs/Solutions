#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    struct pt {
        long long x, y;
        bool operator < (pt & b) const {
            return x < b.x || x == b.x && y < b.y;
        }
        pt operator - (const pt & b) {
            return {x - b.x, y - b.y};
        }
        long long norm() {
            return x * x + y * y;
        }
    };
    auto cross = [](pt a, pt b) {
        return a.x * b.y - b.x * a.y;
    };
    auto ccw = [&](pt a, pt b, pt c) {
        return cross(b - a, c - b);
    };

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pt> p(n);
        for(pt & i : p) cin >> i.x >> i.y;

        sort(p.begin(), p.end());
        stable_sort(p.begin() + 1, p.end(), [&](pt a, pt b) {
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
        long long ans = (h[r] - h[l]).norm(), a = l, b = r;
        auto next = [n](int i) {
            return (i + 1) % n;
        };
        for(int i =0; i<n; ++i) {
            if (cross(h[l] - h[next(l)], h[next(r)] - h[r]) > 0) {
                l = next(l);
            } else {
                r = next(r);
            }
            auto d = (h[r] - h[l]).norm();
            if (ans < d) {
                ans = d;
                a = l;
                b = r;
            }
        }
        cout << h[a].x << ' ' << h[a].y << ' ' << h[b].x << ' ' << h[b].y << '\n';
    }
}