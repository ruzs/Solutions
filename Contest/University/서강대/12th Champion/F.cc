#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, S, E;
	cin >> n >> m >> S >> E;
	vector<tuple<int, int, int>> e;
	for(int i =0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({c, a, b});
	}
	sort(e.rbegin(), e.rend());
	struct disjoint_set {
		vector<int> a;
		disjoint_set(int n) { a.resize(n, -1); }
	
		inline int find(int u) {
			return a[u] < 0 ? u : a[u] = find(a[u]);
		}
		inline int merge(int u, int v) {
			u = find(u);
			v = find(v);
			return u == v ? -1 : a[u] += a[v], a[v] = u;
		}
	} ds(n + 1);
	for(auto& [c, a, b] : e) {
		if (ds.find(a) == ds.find(b)) continue;
		ds.merge(a, b);
		if (ds.find(S) == ds.find(E)) {
			cout << c;
			return 0;
		}
	}
	cout << 0;
}