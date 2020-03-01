#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> distress(n + 1);
	for(int i =1; i<=n; ++i) {
		int p;
		cin >> p;
		if (~p) g[p].push_back(i);
	}
	while(m--) {
		int b, c;
		cin >> b >> c;
		distress[b] += c;
	}
	vector<int> ans(n + 1);
	auto dfs = [&](auto& dfs, int a, int acc)->void {
		ans[a] = acc += distress[a];
		for(int b : g[a]) {
			dfs(dfs, b, acc);
		}
	};
	dfs(dfs, 1, 0);
	for(int i =1; i<=n; ++i) cout << ans[i] << ' ';
}