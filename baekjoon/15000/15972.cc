#include <bits/stdc++.h>

using namespace std;

int n, m, h, i, j, k, a[2005][2005];
priority_queue<tuple<int, int, int>> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> h;
	for(i =0; i<=n<<1; i+=2) {
		for(j =1; j<=m<<1; j+=2) {
			cin >> a[i][j];
		}
	}
	for(i =1; i<=n<<1; i+=2) {
		for(j =0; j<=m<<1; j+=2) {
			cin >> a[i][j];
		}
	}
	for(i =1; i<=n<<1; i+=2) {
		for(j =1; j<=m<<1; j+=2) {
			a[i][j] = h;
			if (i - 2 < 1 && ~a[i - 1][j]) a[i][j] = min(a[i][j], a[i - 1][j]);
			if (j - 2 < 1 && ~a[i][j - 1]) a[i][j] = min(a[i][j], a[i][j - 1]);
			if (i + 2 > n << 1 && ~a[i + 1][j]) a[i][j] = min(a[i][j], a[i + 1][j]);
			if (j + 2 > m << 1 && ~a[i][j + 1]) a[i][j] = min(a[i][j], a[i][j + 1]);
			if (a[i][j] != h) pq.push({-a[i][j], i, j});
		}
	}
	while(pq.size()) {
		auto [w, y, x] = pq.top(); pq.pop();
		if (-w > a[y][x]) continue;
		if (y > 1 && ~a[y - 1][x] && a[y - 2][x] > max(a[y - 1][x], a[y][x])) {
			a[y - 2][x] = max(a[y - 1][x], a[y][x]);
			pq.push({-a[y - 2][x], y - 2, x});
		}
		if (x > 1 && ~a[y][x - 1] && a[y][x - 2] > max(a[y][x - 1], a[y][x])) {
			a[y][x - 2] = max(a[y][x - 1], a[y][x]);
			pq.push({-a[y][x - 2], y, x - 2});
		}
		if (~a[y + 1][x] && a[y + 2][x] > max(a[y + 1][x], a[y][x])) {
			a[y + 2][x] = max(a[y + 1][x], a[y][x]);
			pq.push({-a[y + 2][x], y + 2, x});
		}
		if (~a[y][x + 1] && a[y][x + 2] > max(a[y][x + 1], a[y][x])) {
			a[y][x + 2] = max(a[y][x + 1], a[y][x]);
			pq.push({-a[y][x + 2], y, x + 2});
		}
	}
	int ans = 0;
	for(i =1; i<=n<<1; i+=2) {
		for(j =1; j<=m<<1; j+=2) {
			ans += a[i][j];
		}
	}
	cout << ans;
}