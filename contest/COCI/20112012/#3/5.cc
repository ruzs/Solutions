#include <bits/stdc++.h>

using namespace std;

#define N 1<<19
struct fwt {
	int a[N];
	void add(int p, int x) {
		while(p < N) a[p] += x, p += p & -p;
	}
	auto sum(int p) {
		int r = a[p];
		while(p -= p & -p) r += a[p];
		return r;
	}
} fw;
int n, m, a[N], b, c, s[N], e[N];
vector<int> g[N];

int dfs(int a, int p, int n) {
	s[a] = e[a] = n;
	for(int b : g[a]) {
		if (b != p) e[a] = dfs(b, a, e[a] + 1);
	}
	return e[a];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> a[1];
	for(int i =2; i<=n; ++i) {
		cin >> a[i] >> b;
		g[b].push_back(i);
	}
	dfs(1, 0, 1);
	for(int i =1; i<=n; ++i) {
		fw.add(s[i], a[i]);
		fw.add(s[i] + 1, -a[i]);
	}
	while(m--) {
		char o;
		cin >> o;
		if (o == 'p') {
			cin >> b >> c;
			if (s[b] < e[b]) {
				fw.add(s[b] + 1, c);
				fw.add(e[b] + 1, -c);
			}
		}
		else {
			cin >> b;
			cout << fw.sum(s[b]) << '\n';
		}
	}
}