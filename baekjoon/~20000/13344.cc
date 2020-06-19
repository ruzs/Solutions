#include <bits/stdc++.h>

using namespace std;

struct disjoint_set {
	vector<int> a;
	disjoint_set(int n) { a.resize(n, -1); }

	int find(int u) {
		return a[u] < 0 ? u : a[u] = find(a[u]);
	}
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return -1;
		if (a[u] > a[v]) swap(u, v);
		a[u] += a[v];
		return a[v] = u;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	disjoint_set ds(n);
	vector<pair<int, int>> e;
	for(int i =0; i<m; ++i) {
		int a, b;
		char o;
		cin >> a >> o >> b;
		if (o == '=') ds.merge(a, b);
		else e.push_back({a, b});
	}
	vector<vector<int>> g(n);
	vector<int> in(n);
	for(auto & [a, b] : e) {
		a = ds.find(a);
		b = ds.find(b);
		in[b]++;
		g[a].push_back(b);
	}
	queue<int> q;
	int k = 0;
	for(int i =0; i<n; ++i) if (ds.a[i] < 0) {
		k++;
		if (!in[i]) q.push(i);
	}
	int cnt = 0;
	while(q.size()) {
		int a = q.front(); q.pop();
		cnt++;
		for(int b : g[a]) {
			if (!in[b]) {
				cout << "inconsistent";
				return 0;
			}
			if (!--in[b]) q.push(b);
		}
	}
	if (cnt == k) cout << "consistent";
	else cout << "inconsistent";
}