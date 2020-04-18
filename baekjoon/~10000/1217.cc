#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while(cin >> n >> m) {
		if (!n && !m) break;
		vector<vector<int>> g(2 * m + 1), gt(2 * m + 1);
		for(int i =0; i<n; ++i) {
			int a, b;
			cin >> a >> b;
			auto enc = [](int x) {
				return x < 0 ? -2 * x : 2 * x - 1;
			};
			g[enc(-a)].push_back(enc(b));
			g[enc(-b)].push_back(enc(a));
			gt[enc(b)].push_back(enc(-a));
			gt[enc(a)].push_back(enc(-b));
		}
		vector<int> order, used(2 * m + 1), scc(2 * m + 1);
		function<void(int)> dfs1 = [&](int a) {
			used[a] = 1;
			for(int b : g[a]) {
				if (!used[b]) dfs1(b);
			}
			order.push_back(a);
		};
		function<void(int, int)> dfs2 = [&](int a, int c) {
			used[a] = 0;
			scc[a] = c;
			for(int b : gt[a]) {
				if (used[b]) dfs2(b, c);
			}
		};
		for(int i =1; i<=2*m; ++i) {
			if (!used[i]) dfs1(i);
		}
		int c = 0;
		while(order.size()) {
			int b = order.back();
			order.pop_back();
			if (used[b]) dfs2(b, ++c);
		}
		int ok = 1;
		for(int i =1; i<2*m; i += 2) {
			if (scc[i] == scc[i + 1]) ok = 0;
		}
		cout << ok << '\n';
	}
}