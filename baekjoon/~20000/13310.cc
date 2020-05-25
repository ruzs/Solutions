#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    struct pt {
        long long x, y;
        auto norm() { return x * x + y * y; }
        bool operator<(pt & b) const {
            return x < b.x || x == b.x && y < b.y;
        }
        pt operator - (const pt & b) {
            return {x - b.x, y - b.y};
        }
    };
    auto cross = [](pt a, pt b) {
        return a.x * b.y - b.x * a.y;
    };
    auto ccw = [=](pt a, pt b, pt c) {
        return cross(b - a, c - b);
    };

    int n, m;
    cin >> n >> m;
    
    struct star {
        long long x, y, dx, dy;
        pt position(int day) {
            return {x + dx * day, y + dy * day};
        }
    };
    vector<star> a(n);
    for(star & i : a) cin >> i.x >> i.y >> i.dx >> i.dy;

    auto longest_distance = [&](int day) {
        vector<pt> p, h;
        for(star & i : a) p.push_back(i.position(day));

        sort(p.begin(), p.end());
        stable_sort(p.begin() + 1, p.end(), [&](pt a, pt b){
            return ccw(p[0], a, b) > 0;
        });
        for(pt & i : p) {
            while(h.size() > 1 && ccw(h[h.size() - 2], h.back(), i) <= 0) h.pop_back();
            h.push_back(i);
        }

        int n = h.size();
        int l = 0, r = 0;
        for(int i =0; i<n; ++i) if (h[r].x < h[i].x) r = i;
        long long ans = (h[r] - h[l]).norm();
        for(int i =0; i<n; ++i) {
            if (cross(h[(l + 1) % n] - h[l], h[r] - h[(r + 1) % n]) > 0) l = (l + 1) % n;
            else r = (r + 1) % n;
            ans = max(ans, (h[r] - h[l]).norm());
        }
        return ans;
    };
    int lo = 0, hi = m, m1, m2;
    while(lo + 3 <= hi) {
        m1 = (lo + lo + hi) / 3;
        m2 = (hi + lo + hi) / 3;
        if (longest_distance(m1) > longest_distance(m2)) lo = m1;
        else hi = m2;
    }
    long long ans_day, ans_dist = 1e18;
    for(int i =lo; i<=hi; ++i) {
        auto d = longest_distance(i);
        if (ans_dist > d) {
            ans_dist = d;
            ans_day = i;
        }
    }
    cout << ans_day << '\n' << ans_dist;
}