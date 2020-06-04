#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	struct point { long long x, y, i; };
	vector<point> p = {{0, 0}};
	for(int i =0; i<n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		p.push_back({x1, y2, i});
		p.push_back({x2, y1, i});
	}
	auto ccw = [](point a, point b, point c) {
		return (a.x - b.x) * (b.y - c.y) + (b.x - c.x) * (b.y - a.y);
	};
	sort(p.begin() + 1, p.end(), [&](auto a, auto b) {
		return ccw(p[0], a, b) > 0;
	});
	int cnt = 0, ans = 0;
	vector<int> c(n);
	for(int i =1; i<p.size(); ++i) {
		if (!c[p[i].i]++) cnt++;
		ans = max(ans, cnt);
		if (c[p[i].i] == 2) cnt--;
	}
	cout << ans;
}