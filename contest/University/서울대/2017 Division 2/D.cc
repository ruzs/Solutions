#include <bits/stdc++.h>

using namespace std;

int d[5001];
int dfs(int a, vector<int> g[]) {
	int & ref = d[a];
	if (ref != -1) return ref;

	ref = 1;
	for(int b : g[a]) {
		ref = max(ref, dfs(b, g) + 1);
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, h[5001];
	vector<int> g[5001];

	cin >> n >> m;
	for(int i =1; i<=n; ++i) cin >> h[i];
	while(m--) {
		int a, b;
		cin >> a >> b;
		if (h[a] < h[b])
			g[a].push_back(b);
		else
			g[b].push_back(a);
	}
	memset(d, -1, sizeof d);
	for(int i =1; i<=n; ++i) {
		cout << dfs(i, g) << '\n';
	}
}