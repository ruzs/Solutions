#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for(int i =0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int k;
	cin >> k;
	vector<int> x(n + 1);
	for(int i =0; i<k; ++i) {
		int a;
		cin >> a;
		x[a] = 1;
	}
	set<int> fired;
	for(int i =1; i<=n; ++i) {
		if (!x[i]) continue;
		if (all_of(g[i].begin(), g[i].end(), [&](int a){return x[a];})) fired.insert(i);
	}
	for(int i =1; i<=n; ++i) {
		if (fired.count(i) || !x[i]) continue;
		if (none_of(g[i].begin(), g[i].end(), [&](int a){return fired.count(a);})) {
			cout << -1;
			return 0;
		}
	}
	cout << fired.size() << '\n';
	for(int i : fired) cout << i << ' ';
}