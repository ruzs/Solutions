#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for(int i =0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int timer = 0;
	vector<int> tin(n + 1), low(n + 1);
	set<int> cutpoint;
	auto dfs = [&](auto f, int a, int p)->void {
		tin[a] = low[a] = ++timer;
		int child = 0;
		for(int b : g[a]) {
			if (b == p) continue;
			if (tin[b]) low[a] = min(low[a], tin[b]);
			else {
				f(f, b, a);
				low[a] = min(low[a], low[b]);
				if (p != -1 && tin[a] <= low[b])
					cutpoint.insert(a);
				child++;
			}
		}
		if (p == -1 && child > 1)
			cutpoint.insert(a);
	};
	for(int i =1; i<=n; ++i) {
		if (!tin[i]) dfs(dfs, i, -1);
	}
	cout << cutpoint.size() << '\n';
	for(int i : cutpoint) {
		cout << i << ' ';
	}
}