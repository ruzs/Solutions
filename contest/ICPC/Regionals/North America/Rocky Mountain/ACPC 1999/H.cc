#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> g;
int mx, l;
void dfs(int a, int acc, int p = 0) {
	if (mx < acc) mx = acc, l = a;
	for(auto& [b, c] : g[a]) {
		if (b == p) continue;
		dfs(b, acc + c, a);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int u, v, w;
	while(cin >> u >> v >> w) {
		g.resize(max<int>(g.size(), max(u, v) + 1));
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	if (g.empty()) cout << "0\n";
	else {
		dfs(1, 0);
		dfs(l, 0);
		cout << mx;
	}
}