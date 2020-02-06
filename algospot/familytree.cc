#include <bits/stdc++.h>

using namespace std;

#define N 17

int p[1<<N][N], h[1<<N] = {1};
vector<int> g[1<<N];

void preproc(int a) {
	for(int b : g[a]) if (b != p[a][0]) {
		h[b] = h[a] + 1;
		p[b][0] = a;
		for(int j =1; j<N; ++j)
			p[b][j] = p[p[b][j - 1]][j - 1];
		preproc(b);
	}
}
int lca(int a, int b) {
	if (h[a] > h[b]) swap(a, b);
	for(int j =N-1; ~j; --j)
		if (h[a] <= h[p[b][j]]) b = p[b][j];
	if (a == b) return a;
	for(int j =N-1; ~j; --j)
		if (p[a][j] != p[b][j]) {
			a = p[a][j];
			b = p[b][j];
		}
	return p[a][0];
}
void solve() {
	memset(p, 0, sizeof p);
	memset(g, 0, sizeof g);
	int n, m, p;
	cin >> n >> m;
	for(int i =1; i<n; ++i) {
		cin >> p;
		g[p].push_back(i);
	}
	preproc(0);
	while(m--) {
		int a, b;
		cin >> a >> b;
		cout << h[a] + h[b] - 2*h[lca(a, b)] << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}