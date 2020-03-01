#include <bits/stdc++.h>

using namespace std;

struct disjoint_set {
	vector<int> a;
	disjoint_set(int n) {
		a.assign(n, -1);
	}
	int find(int u) {
		return a[u] < 0 ? u : a[u] = find(a[u]);
	}
	int size(int u) {
		return -a[find(u)];
	}
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u != v) {
			a[u] += a[v];
			a[v] = u;
		}
		return u;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	priority_queue<pair<int, int>> pq;
	for(int i =0; i<n; ++i) {
		cin >> a[i];
		pq.push({a[i], i});
	}
	vector<tuple<int, int, int>> b;
	for(int i =0; i<m; ++i) {
		int x, y;
		cin >> x >> y;
		b.emplace_back(x, y, i);
	}
	sort(b.rbegin(), b.rend());
	disjoint_set ds(n);
	vector<int> ans(m, 0);
	int mx = 0;
	for(auto & [x, y, i] : b) {
		while(pq.size()) {
			if (pq.top().first <= x) break;
			int j = pq.top().second; pq.pop();
			if (j > 0 && a[j - 1] > x)
				ds.merge(j, j - 1);
			if (j < n - 1 && a[j + 1] > x)
				ds.merge(j, j + 1);
			mx = max(mx, ds.size(j));
		}
		if (y >= mx + 1) ans[i] = 1;
	}
	for(int i : ans) cout << i << '\n';
}