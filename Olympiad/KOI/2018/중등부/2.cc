#include <bits/stdc++.h>

using namespace std;

int n, s, e, a, b, c;
pair<int, int> f[100005];
vector<pair<int, int>> g[100005];
int dfs(int a, int p) {
	if (a == e) return 0;
	for(auto & [b, c] : g[a]) {
		if (b == p) continue;
		int r = dfs(b, a) + c;
		if (r < 1e9) {
			f[b] = {a, c};
			return r;
		}
	}
	return 1e9;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s >> e;
	while(n--) {
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	int r = dfs(s, 0);
	int mx = 0;
	while(e) {
		mx = max(mx, f[e].second);
		e = f[e].first;
	}
	cout << r - mx;
}