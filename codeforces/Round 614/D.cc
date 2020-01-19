#include <bits/stdc++.h>
using namespace std;

typedef struct { long long x, y; } point;
long long xi, yi, ax, ay, bx, by, sx, sy, t;
vector<point> v;

long long dist(point a, point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int main() {
	cin >> xi >> yi >> ax >> ay >> bx >> by >> sx >> sy >> t;
	v.push_back({xi, yi});
	while(v.back().x <= 1e16 && v.back().y <= 1e16) {
		v.push_back({ax * v.back().x + bx, ay * v.back().y + by});
	}
	int ans = 0;
	for(int i =0; i<v.size(); ++i) {
		long long s = dist({sx, sy}, v[i]);
		if (s > t) continue;
		int cnt = 1;
		for(int j =i; j; --j) {
			s += dist(v[j], v[j - 1]);
			if (s > t) break;
			cnt++;
		}
		if (i < v.size() - 1) {
			s += dist(v[0], v[i + 1]);
			if (s <= t) {
				cnt++;
				for(int j =i + 2; j<v.size(); ++j) {
					s += dist(v[j - 1], v[j]);
					if (s > t) break;
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}