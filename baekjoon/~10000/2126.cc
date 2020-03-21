#include <bits/stdc++.h>

using namespace std;

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
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, f;
	cin >> n >> m >> f;
	struct E { int a, b, c, t; };
	vector<E> e;
	for(int i =0; i<m; ++i) {
		int a, b, c, t;
		cin >> a >> b >> c >> t;
		e.push_back({a, b, c, t});
	}
	double lo = 0, hi = f, md;
	for(int i =0; i<100; ++i) {
		md = (lo + hi) / 2;
		sort(e.begin(), e.end(), [md](auto& a, auto& b) {
			return md * a.t + a.c < md * b.t + b.c;
		});
		disjoint_set ds(n + 1);
		double sum = 0;
		for(auto & i : e) {
			if (~ds.merge(i.a, i.b)) {
				sum += i.t * md + i.c;
			}
		}
		if (sum <= f) lo = md;
		else hi = md;
	}
	printf("%.4lf", md);
}