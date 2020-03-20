#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> s(n);
	for(int i =0; i<n; ++i) {
		cin >> s[i].first >> s[i].second;
	}
	vector<string> t(n);
	for(int i =0; i<n; ++i) {
		cin >> t[i];
	}
	int w;
	cin >> w;

	priority_queue<tuple<int, int, int>> pq;
	vector<array<int, 2>> d(1 << n, {(int)1e9, (int)1e9});
	vector<int> pos(1 << n);
	for(int i =0; i<1<<n; ++i) {
		int sum = 0, mx = 0, ok = 1;
		for(int j =0; j<n; ++j) {
			if (i & 1 << j) {
				sum += s[j].first;
				mx = max(mx, s[j].second);
				int subok = __builtin_popcount(i) == 1;
				for(int k =0; k<n; ++k) {
					if (j == k) continue;
					if (i & 1 << k) subok |= t[j][k] == 'Y';
				}
				ok &= subok;
			}
		}
		pos[i] = ok && sum <= w ? mx : -1;
	}
	pq.push({0, (1 << n) - 1, 0});
	d[(1 << n) - 1][0] = 0;
	while(pq.size()) {
		auto [c, a, x] = pq.top(); pq.pop();
		if (a + 1 == 1 << n && x) {
			cout << -c;
			return 0;
		}
		if (d[a][x] < -c) continue;
		for(int s = a; s; s = a & s - 1) {
			if (~pos[s]) {
				int b = (~a & ((1<<n) - 1)) ^ s;
				int nc = -c + pos[s];
				if (d[b][x^1] > nc) {
					d[b][x^1] = nc;
					pq.push({-nc, b, x^1});
				}
			}
		}
	}
	cout << -1;
}