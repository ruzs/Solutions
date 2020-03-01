#include <bits/stdc++.h>

using namespace std;

int n, m, k, x[10001];
vector<int> g[10001];

bool v[10001];
int dfs(int a) {
	v[a] = 1;
	int r = x[a];
	for(int b : g[a]) {
		if (!v[b]) r = min(r, dfs(b));
	}
	return r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i<=n; ++i) cin >> x[i];
	while(m--){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans =0;
	for(int i =1; i<=n; ++i) {
		if (!v[i]) ans += dfs(i);
	}
	if (ans > k) cout << "Oh no";
	else cout << ans;
}