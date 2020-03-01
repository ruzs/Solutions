#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct fenwick {
	vector<T> a;
	int n;
	fenwick(int _n) : n(_n) {
		a.resize(n);
	}
	void add(int p, T x) {
		while(p < n) {
			a[p] += x;
			p += p & -p;
		}
	}
	T sum(int p) {
		T r{};
		while(p) {
			r += a[p];
			p -= p & -p;
		}
		return r;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for(int i =1; i<=n; ++i) {
		int p;
		cin >> p;
		if (~p) g[p].push_back(i);
	}
	vector<int> dfs_a(1), sz(n + 1), idx(n + 1);
	function<int(int)> dfs = [&](int a) {
		idx[a] = dfs_a.size();
		dfs_a.push_back(a);
		for(int b : g[a]) {
			sz[a] += dfs(b);
		}
		return ++sz[a];
	};
	dfs(1);
	fenwick<int> fw(dfs_a.size());
	while(m--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			fw.add(idx[b], c);
			fw.add(idx[b] + sz[b], -c);
		}
		else {
			cin >> b;
			cout << fw.sum(idx[b]) << '\n';
		}
	}
}