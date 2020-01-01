#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, n, m, a, b;
	vector<list<int>> li;
	function<int(int)> dfs = [&](int state) {
		if (state == (1 << n) - 1) return 1;
		int res = 0;
		for (int i = 0; i < n; ++i)
			if (~state & (1 << i)) {
				for (int j : li[i])
					if (~state & (1 << j)) {
						res += dfs(state | (1 << i) | (1 << j));
					}
				break;
			}
		return res;
	};
	cin >> t;
	while (t--) {
		cin >> n >> m;
		li.clear();
		li.resize(n);
		while (m--) {
			cin >> a >> b;
			li[a].push_back(b);
			li[b].push_back(a);
		}
		cout << dfs(0) << '\n';
	}
}
