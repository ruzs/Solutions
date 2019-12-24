#include <bits/stdc++.h>
using namespace std;

int n, m, t, k, ans, ansx, ansy;
map<int, int> mp;
struct point{
	int x, y, i;
} p[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> t >> k;
	for(int i =0; i<t; ++i) {
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + t, [](auto& a, auto& b) {
		return a.x < b.x;
	});
	for(int i =0; i<t; ++i) {
		mp[p[i].y]++;
		for(int j =i + 1; j<t; ++j) {
			if (p[i].x + k < p[j].x) break;
			mp[p[j].y]++;
		}
		for(auto j = mp.begin(); j != mp.end(); ++j) {
			int cnt = 0;
			for(auto l = j; l != mp.end(); ++l) {
				if (j->first + k < l->first) break;
				cnt += l->second;
			}
			if (ans < cnt) {
				ans = cnt;
				ansx = min(m - k, p[i].x);
				ansy = min(n - k, j->first) + k;
			}
		}
		mp.clear();
	}
	cout << ansx << ' ' << ansy << '\n' << ans;
}
