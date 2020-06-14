#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, tc = 0;
	while(cin >> n) {
		if (!n) break;

		struct pt {
			int x, y;
			bool operator < (pt & b) const {
				return x < b.x || x == b.x && y < b.y; }
			pt operator - (const pt& b) {
				return {x - b.x, y - b.y}; }
			int norm() { return x * x + y * y; }
		};
		auto cross = [](pt a, pt b) {
			return a.x * b.y - b.x * a.y;
		};
		auto ccw = [=](pt a, pt b, pt c) {
			return cross(c - b, b - a);
		};
		vector<pt> p(n), h;
		for(pt & i : p) cin >> i.x >> i.y;
		sort(p.begin(), p.end());
		stable_sort(p.begin() + 1, p.end(), [&](pt a, pt b){
			return ccw(p[0], a, b) > 0;
		});
		for(pt & i : p) {
			while(h.size() > 1 && ccw(h[h.size()-2], h.back(), i) <= 0) h.pop_back();
			h.push_back(i);
		}

		n = h.size();
		double ans = 1e9;
		for(int i =0; i<n; ++i) {
			pt low = h[(i + 1) % n] - h[i];
			double mx = 0;
			for(int j =0; j<n; ++j) {
				pt hypo = h[j] - h[i];
				mx = max(mx, fabs(cross(low, hypo)) / sqrt(low.norm()));
			}
			ans = min(ans, mx);
		}
		cout.precision(2);
		cout << "Case " << ++tc << ": " << fixed << ceil(ans * 100) / 100 << '\n';
	}
}