#include <bits/stdc++.h>
using namespace std;

int n, m, f;
bool v[2001];
vector<int> g[2001];

void dfs(int a, int d) {
	if (d == 5) f = 1;
	v[a] = 1;
	for(int b : g[a]) {
		if (!f && !v[b]) dfs(b, d + 1);
	}
	v[a] = 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while(m--) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i =0; i<n; ++i) {
		if (!f) dfs(i, 1);
	}
	cout << f;
}
