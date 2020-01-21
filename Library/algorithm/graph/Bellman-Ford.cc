#define N 10005

vector<pair<int, int>> g[N];

auto bellman_ford(int n, int src) {
	vector<int> d(N, 1e9), minusCycle = {-1};
	d[src] = 0;

	for(int i =1; i<=n; ++i) {
		bool update = 0;
		for(int a =1; a<=n; ++a) {
			if (d[a] == 1e9) continue;
			for(auto& [b, c] : g[a]) {
				if (d[b] > d[a] + c) {
					d[b] = d[a] + c;
					update = 1;
					if (i == n) return minusCycle;
				}
			}
		}
		if (!update) break;
	}
	return d;
}