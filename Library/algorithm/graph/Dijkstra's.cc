#define N 100005

vector<pair<int, int>> g[N];
auto dijkstra(int src) {
	priority_queue<pair<int, int>> pq;
	vector<int> d(N, 1e9);

	pq.push({ 0, src });
	d[src] = 0;

	while(pq.size()) {
		int c = -pq.top().first;
		int a = pq.top().second; pq.pop();
		if (c > d[a]) continue;
		for(auto& [b, w] : g[a]) {
			int nc = c + w;
			if (d[b] > nc) {
				d[b] = nc;
				pq.push({ -nc, b });
			}
		}
	}
	return d;
}