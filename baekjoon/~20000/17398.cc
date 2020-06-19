#include <bits/stdc++.h>

using namespace std;

struct disjoint_set {
	vector<int> a;
	disjoint_set(int n) { a.resize(n, -1); }

	int find(int u) {
		return a[u] < 0 ? u : a[u] = find(a[u]);
	}
	int size(int u) {
		return -a[find(u)];
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

	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> e(m + 1);
	disjoint_set ds(n + 1);
	for(int i =1; i<=m; ++i) {
		cin >> e[i].first >> e[i].second;
	}
	vector<int> q(k);
	set<int> s;
	for(int i =1; i<=m; ++i) s.insert(i);
	for(int & i : q) cin >> i, s.erase(i);
	reverse(q.begin(), q.end());
	for(int i : s) ds.merge(e[i].first, e[i].second);
	long long ans = 0;
	for(int i : q) {
		if (ds.find(e[i].first) != ds.find(e[i].second)) {
			ans += ds.size(e[i].first) * ds.size(e[i].second);
			ds.merge(e[i].first, e[i].second);
		}
	}
	cout << ans;
}