#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    struct pt {
        long long x, y;
        pt operator-(const pt & b) {
            return {x - b.x, y - b.y};
        }
        bool operator<(const pt & b) const {
            return x < b.x || x == b.x && y < b.y;
        }
    };
    auto cross = [](pt a, pt b) {
        return a.x * b.y - b.x * a.y;
    };
    auto ccw = [=](pt a, pt b, pt c) {
        auto cw = cross(b - a, c - b);
        return cw ? cw < 0 ? -1 : 1 : 0;
    };

    pt a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    if (ccw(a, b, c) * ccw(a, b, d) > 0 || ccw(c, d, a) * ccw(c, d, b) > 0) cout << 0;
    else if (cross(a - b, c - d) == 0 && (max(a, b) < min(c, d) || max(c, d) < min(a, b))) cout << 0;
    else cout << 1;
}