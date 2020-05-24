#include <bits/stdc++.h>

using namespace std;

constexpr int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};

struct Q {
	int y1, x1, y2, x2;
	long long ans = 1e18;
} qry[100000];

long long a[5][100000], dist[5][100000];

priority_queue<pair<long long, pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m;
	for(int i =0; i<n; ++i) for(int j =0; j<m; ++j) cin >> a[i][j];

	cin >> k;
	vector<int> q(k);
	for(int i =0; i<k; ++i) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		qry[i] = {y1 - 1, x1 - 1, y2 - 1, x2 - 1};
		q[i] = i;
	}
	auto valid = [n, m](int y, int x)
		{ return y >= 0 && x >= 0 && y < n && x < m; };
	auto dijkstra = [&](auto src, int l, int r) {
		for(int i =0; i<n; ++i) for(int j =l; j<=r; ++j)
			dist[i][j] = 1e18;
		pq.push({0, src});
		dist[src.first][src.second] = 0;
		while(pq.size()) {
			long long c = -pq.top().first;
			auto [y, x] = pq.top().second; pq.pop();
			if (c > dist[y][x]) continue;
			for(int w =0; w<4; ++w) {
				int ny = y + dy[w], nx = x + dx[w];
				if (!valid(ny, nx) || x < l || x > r) continue;
				long long nc = c + a[ny][nx];
				if (dist[ny][nx] > nc) {
					dist[ny][nx] = nc;
					pq.push({-nc, {ny, nx}});
				}
			}
		}
	};
	function<void(vector<int>&, int, int)> dc;
	dc = [&](auto & q, int l, int r) {
		if (q.empty() || l > r) return;
		int m = l + r >> 1;
		for(int i =0; i<n; ++i) {
			dijkstra(make_pair(i, m), l, r);
			for (int j : q) {
				auto & [y1, x1, y2, x2, ans] = qry[j];
				ans = min(ans, dist[y1][x1] + dist[y2][x2] + a[i][m]);
			}
		}
		vector<int> q1, q2;
		for(int j : q) {
			if (qry[j].x1 < m && qry[j].x2 < m) q1.push_back(j);
			else if (qry[j].x1 > m && qry[j].x2 > m) q2.push_back(j);
		}
		dc(q1, l, m - 1);
		dc(q2, m + 1, r);
	};
	dc(q, 0, m - 1);
	for(int i =0; i<k; ++i) cout << qry[i].ans << '\n';
}