#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	long long k;
	cin >> n >> m >> k;
	vector<tuple<int, int, int>> e;
	for(int i =1; i<=n; ++i) {
		int s;
		cin >> s;
		e.push_back({s, i, 0});
	}
	bitset<1000001> t;
	for(int i =0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (a == 1 && b == n) t[b] = 1;
		else t[a] = 1;
	}
	if (m <= 1) {
		cout << "YES";
		return 0;
	}
	for(int i =1; i<n; ++i) {
		e.push_back({t[i] ? 1e9 : 0, i, i + 1});
	}
	e.push_back({t[n] ? 1e9 : 0, n, 1});
	sort(e.begin(), e.end());
	struct disjoint_set {
		vector<int> a;
		disjoint_set(int n) { a.resize(n, -1); }
	
		int find(int u) {
			return a[u] < 0 ? u : a[u] = find(a[u]);
		}
		int merge(int u, int v) {
			u = find(u); v = find(v);
			return u == v ? -1 : (a[u] += a[v], a[v] = u);
		}
	} ds(n + 1);
	long long sum = 0;
	for(auto & [c, a, b] : e) {
		if (~ds.merge(a, b)) sum += c;
	}
	cout << (sum <= k ? "YES" : "NO");
}