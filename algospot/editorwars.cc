#include <bits/stdc++.h>

using namespace std;

struct dsu {
	int a[10005], e[10005];
	dsu() {
		memset(a, -1, sizeof a);
		memset(e, -1, sizeof e);
	}
	int find(int u) {
		return a[u] < 0 ? u : a[u] = find(a[u]);
	}
	int size(int u) {
		return -a[find(u)];
	}
	int merge(int u, int v) {
		if (u < 0 || v < 0) return max(u, v);
		u = find(u), v = find(v);
		if (u == v) return u;
		a[u] += a[v];
		return a[v] = u;
	}
	bool dis(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return 1;
		e[u] = merge(e[u], v);
		e[v] = merge(u, e[v]);
		return 0;
	}
	bool ack(int u, int v) {
		u = find(u), v = find(v);
		if (e[u] == v) return 1;
		int a = merge(u, v), b = merge(e[u], e[v]);
		e[a] = b;
		if (~b) e[b] = a;
		return 0;
	}
};

void solve() {
	int n, m, a, b, mosun = 0;
	dsu ds;
	string s;
	cin >> n >> m;
	for(int i =1; i<=m; ++i) {
		cin >> s >> a >> b;
		if (s == "ACK") {
			if (ds.ack(a, b) && !mosun) mosun = i;
		}
		else {
			if (ds.dis(a, b) && !mosun) mosun = i;
		}
	}
	if (mosun) cout << "CONTRADICTION AT " << mosun << '\n';
	else {
		int ans = 0;
		for(int i =0; i<n; ++i) {
			if (ds.find(i) == i) {
				int e = ds.e[i];
				if (i < e) continue;
				if (e == -1) ans += ds.size(i);
				else ans += max(ds.size(i), ds.size(e));
			}
		}
		cout << "MAX PARTY SIZE IS " << ans << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}