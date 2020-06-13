#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> X, Y, x(n), y(n);
	for(int i =0; i<n; ++i) {
		cin >> x[i] >> y[i];
		X.push_back(x[i]);
		Y.push_back(y[i]);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.resize(unique(X.begin(), X.end()) - X.begin());
	Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
	x.push_back(x[0]);
	y.push_back(y[0]);
	for(int & i : x) i = lower_bound(X.begin(), X.end(), i) - X.begin();
	for(int & i : y) i = lower_bound(Y.begin(), Y.end(), i) - Y.begin();
	int g[2005][2005]{}, s[2005][2005]{};
	for(int i =0; i<n; ++i) {
		if (x[i] == x[i + 1]) {
			int s = min(y[i], y[i + 1]) * 2 + 1;
			int e = max(y[i], y[i + 1]) * 2 + 1;
			for(int j =s; j<=e; ++j) g[j][x[i]*2+1] = 1;
		} else {
			int s = min(x[i], x[i + 1]) * 2 + 1;
			int e = max(x[i], x[i + 1]) * 2 + 1;
			for(int j =s; j<=e; ++j) g[y[i]*2+1][j] = 1;
		}
	}
	for(int i =0; i<X.size()-1; ++i) {
		for(int j =0; j<Y.size()-1; ++j) {
			s[j*2+2][i*2+2] = (X[i+1] - X[i]) * (Y[j+1] - Y[j]);
		}
	}
	s[0][0] = -1e9;
	constexpr int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
	constexpr int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
	auto valid = [n](int y, int x)
		{ return y >= 0 && x >= 0 && y < n*2 && x < n*2; };
	
	int ans = 0;
	for(int i =0; i<2*n; ++i) {
		for(int j =0; j<2*n; ++j) {
			if (!g[i][j]) {
				queue<pair<int, int>> q;
				q.push({i, j});
				g[i][j] = 1;
				int sum = 0;
				while(q.size()) {
					auto [y, x] = q.front(); q.pop();
					sum += s[y][x];
					for(int w =0; w<4; ++w) {
						int ny = y + dy[w], nx = x + dx[w];
						if (valid(ny, nx) && !g[ny][nx]) {
							g[ny][nx] = 1;
							q.push({ny, nx});
						}
					}
				}
				ans = max(ans, sum);
			}
		}
	}
	cout << ans;
}