#include <bits/stdc++.h>

using namespace std;

struct edge {
	int s, e, x;
} e[200005];
vector<int> g[200005];
int v[200005];
void dfs(int x, int a) {
	v[a] = 1;
	for(int i : g[a]) {
		int b = e[i].s + e[i].e - a;
		e[i].x = e[i].s == a ? x : x ^ 1;
		if (v[b]) continue;
		dfs(x^1, b);
	}
}
bool isOddCycle(int a) {
	for(int i : g[a]) {
		int b = e[i].s + e[i].e - a;
		if (v[b] < 0) return (v[a] - v[b]) % 2 == 0;
		if (!v[b]) {
			v[b] = v[a] - 1;
			if (isOddCycle(b)) return 1;
		}
	}
	v[a] = 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i =0; i<m; ++i) {
		cin >> e[i].s >> e[i].e;
		g[e[i].s].push_back(i);
		g[e[i].e].push_back(i);
	}
	v[1] = -1;
	if (isOddCycle(1)) cout << "NO";
	else {
		memset(v, 0, sizeof v);
		cout << "YES\n";
		dfs(1, 1);
		for(int i =0; i<m; ++i) {
			cout << e[i].x;
		}
	}
}