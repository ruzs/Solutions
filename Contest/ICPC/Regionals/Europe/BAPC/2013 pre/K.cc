#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<string> g(n + 2);
		g[0].resize(m + 2, '.');
		for(int i =1; i<=n; ++i) {
			cin >> g[i];
			g[i] = "." + g[i] + ".";
		}
		g[n+1].resize(m + 2, '.');
		bitset<26> key;
		string key_s;
		cin >> key_s;
		if (key_s != "0") {
			for(char c : key_s) key[c - 'a'] = 1;
		}
		queue<pair<int, int>> q;
		vector<vector<int>> v(n + 2, vector<int>(m + 2));
		vector<vector<pair<int, int>>> door(26);
		const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
		const int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
		auto valid = [&](int y, int x) {
			return y >= 0 && x >= 0 && y < n + 2 && x < m + 2;
		};
		q.push({0, 0});
		v[0][0] = 1;
		int cnt = 0;
		while(q.size()) {
			auto [y, x] = q.front(); q.pop();
			if (g[y][x] == '$') cnt++;
			for(int w= 0; w<4; ++w) {
				int ny = y + dy[w], nx = x + dx[w];
				char c;
				if (valid(ny, nx) && (c = g[ny][nx]) != '*' && !v[ny][nx]) {
					v[ny][nx] = 1;
					if (islower(c)) {
						if (!key[c - 'a']) {
							key[c - 'a'] = 1;
							auto & ref = door[c - 'a'];
							while(ref.size()) {
								q.push(ref.back());
								ref.pop_back();
							}
						}
						q.push({ny, nx});
					} else if (isupper(c)) {
						if (key[c - 'A']) q.push({ny, nx});
						else door[c - 'A'].push_back({ny, nx});
					} else {
						q.push({ny, nx});
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}