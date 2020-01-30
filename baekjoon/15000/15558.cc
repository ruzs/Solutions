	#include <bits/stdc++.h>

	using namespace std;

	int main() {
		int n, k, d[2][100001]{};
		cin >> n >> k;
		string g[2];
		cin >> g[0] >> g[1];

		queue<pair<int, int>> q;
		q.push({0, 0});
		d[0][0] = 1;

		while(q.size()) {
			auto [r, c] = q.front(); q.pop();
			if (c + k >= n || c + 1 == n) return cout << 1, 0;
			if (g[r][c + 1] == '1' && !d[r][c + 1]) {
				d[r][c + 1] = d[r][c] + 1;
				q.push({r, c + 1});
			}
			if (g[r][c - 1] == '1' && c > d[r][c] && !d[r][c - 1]) {
				d[r][c - 1] = d[r][c] + 1;
				q.push({r, c - 1});
			}
			if (g[!r][c + k] == '1' && !d[!r][c + k]) {
				d[!r][c + k] = d[r][c] + 1;
				q.push({!r, c + k});
			}
		}
		cout << 0;
	}