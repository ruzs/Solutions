struct dsu {
	int a[100005];
	dsu() { memset(a, -1, sizeof a); }
	int find(int u) {
		return a[u] < 0 ? u : a[u] = find(a[u]);
	}
	int size(int u) {
		return -a[find(u)];
	}
	int merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return 0;
		a[u] += a[v];
		a[v] = u;
		return -a[u];
	}
};