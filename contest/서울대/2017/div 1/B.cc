#include <bits/stdc++.h>

using namespace std;

int d[5001];
int dfs(int a, int h[], vector<int> g[]) {
	int & ref = d[a];
	if (ref != -1) return ref;

	ref = 1;
	for(int b : g[a]) {
		if (h[b] > h[a]) {
			ref = max(ref, dfs(b, h, g) + 1);
		}
	}
	return ref;
}
int main() {
	int n, m, h[5001];
	vector<int> g[5001];

	cin >> n >> m;
	for(int i =1; i<=n; ++i) cin >> h[i];
	while(m--) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(d, -1, sizeof d);
	for(int i =1; i<=n; ++i) {
		cout << dfs(i, h, g) << '\n';
	}
}