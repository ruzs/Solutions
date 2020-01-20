#include <bits/stdc++.h>

using namespace std;

queue<int> q;
vector<int> g[3001];
int d[3001];
bool v[3001];
//return starting cycle node
int dfs(int a, int p) {
	v[a] = 1;
	for(int b : g[a]) {
		if (b == p) continue;
		
		if (v[b]) {
			q.push(a);
			d[a] = 0;
			return b;
		}
		int r = dfs(b, a);
		if (r > 0) {
			q.push(a);
			d[a] = 0;
			return r == a ? -1 : r;
		}
	}
	return -1;
}
int main() {
	int n;
	cin >> n;
	for(int i =0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(d, -1, sizeof d);
	dfs(1, 0);

	while(q.size()) {
		int a = q.front(); q.pop();
		for(int b : g[a]) {
			if (d[b] == -1) {
				d[b] = d[a] + 1;
				q.push(b);
			}
		}
	}
	for(int i =1; i<=n; ++i) cout << d[i] << ' ';
}