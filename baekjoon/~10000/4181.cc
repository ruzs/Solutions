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
    };
    auto ccw = [](pt a, pt b, pt c) {
        return (a.x - b.x) * (b.y - c.y) + (b.x - c.x) * (b.y - a.y);
    };
    int n;
    cin >> n;
    vector<pt> p;
    for(int i =0; i<n; ++i) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'Y') p.push_back({x, y});
    }

    sort(p.begin(), p.end());
    vector<pt> uh, dh;
    for(int i =0; i<p.size(); ++i) {
        while(uh.size() > 1 && ccw(uh[uh.size() - 2], uh.back(), p[i]) < 0) uh.pop_back();
        uh.push_back(p[i]);
    }
    for(int i =p.size() - 1; i>=0; --i) {
        while(dh.size() > 1 && ccw(dh[dh.size() - 2], dh.back(), p[i]) < 0) dh.pop_back();
        dh.push_back(p[i]);
    }
    uh.insert(uh.end(), dh.begin() + 1, dh.end() - 1);
    cout << uh.size() << '\n';
    for(pt & i : uh) cout << i.x << ' ' << i.y << '\n';
}