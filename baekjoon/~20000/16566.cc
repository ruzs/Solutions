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
		a[u] += a[v];
		return a[v] = u;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(4000001), b;
	for(int i =0; i<m; ++i) {
		int x; cin >> x;
		a[x] = 1;
	}
	for(int i =0; i<4000001; ++i) {
		if (a[i]) b.push_back(i);
	}
	disjoint_set ds(m + 1);
	for(int i =0; i<k; ++i) {
		int x; cin >> x;
		int y = upper_bound(b.begin(), b.end(), x) - b.begin();
		int z = ds.find(y);
		cout << b[z] << '\n';
		ds.merge(z + 1, z);
	}
}