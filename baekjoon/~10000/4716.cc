#include <bits/stdc++.h>

using namespace std;

struct ballun {
	int k, da, db;
	bool operator<(const ballun& b) const {
		return abs(da - db) < abs(b.da - b.db);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	while(cin >> n >> a >> b) {
		if (!n && !a && !b) break;
		priority_queue<ballun> pq;
		for(int i =0; i<n; ++i) {
			int k, da, db;
			cin >> k >> da >> db;
			pq.push({ k, da, db });
		}
		int ans = 0;
		while(pq.size()) {
			auto [k, da, db] = pq.top(); pq.pop();
			if (da < db) {
				if (a < k) {
					ans += a * da;
					ans += (k - a) * db;
					b -= (k - a);
					a = 0;
				} else {
					ans += k * da;
					a -= k;
				}
			} else {
				if (b < k) {
					ans += b * db;
					ans += (k - b) * da;
					a -= (k - b);
					b = 0;
				} else {
					ans += k * db;
					b -= k;
				}
			}
		}
		cout << ans << '\n';
	}
}