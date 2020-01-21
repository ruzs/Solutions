#define N 100005
struct dsu {
	int a[N];
	void init() {
		memset(a, -1, sizeof a);
	}
	int find(int u) {
		return a[u] < 0 ? u : a[u] = find(a[u]);
	}
	int size(int u) {
		return -a[find(u)];
	}
	int merge(int u, int v) {
		u = find(u); v = find(v);
		if (u != v) a[u] += a[v], a[v] = u;
		return -a[u];
	}
};