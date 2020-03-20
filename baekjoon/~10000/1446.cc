#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	map<int, vector<pair<int, int>>> route;
	for(int i =0; i<n; ++i) {
		int s, e, x;
		cin >> s >> e >> x;
		route[s].push_back({e, x});
	}
	priority_queue<pair<int, int>> pq;
	vector<int> d(m + 1, 1e9);
	pq.push({0, 0});
	d[0] = 0;
	while(pq.size()) {
		auto [c, a] = pq.top(); pq.pop();
		if (a == m) break;
		for(auto& [b, w] : route[a]) {
			if (d[b] > -c + w) {
				d[b] = -c + w;
				pq.push({ -d[b], b });
			}
		}
		if (d[a + 1] > -c + 1) {
			d[a + 1] = -c + 1;
			pq.push({ -d[a + 1], a + 1 });
		}
	}
	cout << d[m];
}