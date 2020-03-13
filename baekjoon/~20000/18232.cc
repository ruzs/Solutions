#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, s, e;
	cin >> n >> m >> s >> e;
	vector<vector<int>> g(n + 1);
	for(int i =0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i =1; i<=n; ++i) {
		if (i > 1) g[i].push_back(i - 1);
		if (i < n) g[i].push_back(i + 1);
	}
	queue<int> q;
	q.push(s);
	bitset<300001> v;
	v[s] = 1;
	int qs = q.size(), cnt = 0;
	while(qs--) {
		int a = q.front(); q.pop();
		if (a == e) {
			cout << cnt;
			return 0;
		}
		for(int b : g[a]) {
			if (!v[b]) {
				v[b] = 1;
				q.push(b);
			}
		}
		if (!qs) {
			qs = q.size();
			cnt++;
		}
	}
}