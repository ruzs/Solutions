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
		vector<vector<int>> g(n + 1);
		for(int i =0; i<m; ++i) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		if (n == m + 1) {
			vector<int> v(n + 1, 0);
			int cnt = 0;
			function<void(int)> dfs = [&](int a) {
				v[a] = 1;
				cnt++;
				for(int b : g[a]) {
					if (!v[b]) dfs(b);
				}
			};
			dfs(1);
			if (cnt == n) cout << "tree\n";
			else cout << "graph\n";
		}
		else cout << "graph\n";
	}
}