#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(m * 2), gt(m * 2);
	vector<int> scc(m * 2), used(m * 2), chs(m), ord;
	auto enc = [](int x) {
		return x > 0 ? 2 * (x - 1) : -2 * x - 1;
	};
	for(int i =0; i<n; ++i) {
		int a, sa, b, sb;
		cin >> a >> sa >> b >> sb;
		if (!sa) a = -a;
		if (!sb) b = -b;
		g[enc(-a)].push_back(enc(b));
		g[enc(-b)].push_back(enc(a));
		gt[enc(a)].push_back(enc(-b));
		gt[enc(b)].push_back(enc(-a));
	}
	function<void(int)> dfs1 = [&](int a) {
		used[a] = 1;
		for(int b : g[a]) {
			if (!used[b]) dfs1(b);
		}
		ord.push_back(a);
	};
	function<void(int, int)> dfs2 = [&](int a, int c) {
		used[a] = 0;
		scc[a] = c;
		for(int b : gt[a]) {
			if (used[b]) dfs2(b, c);
		}
	};
	for(int i =0; i<2*m; ++i)
		if (!used[i]) dfs1(i);
	int c = 0;
	while(ord.size()) {
		int b = ord.back();
		ord.pop_back();
		if (used[b]) dfs2(b, ++c);
	}
	for(int i =0; i<2*m; i+=2) {
		if (scc[i] == scc[i + 1]) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		chs[i / 2] = scc[i] > scc[i + 1];
	}
	for(int i : chs) cout << i << '\n';
}