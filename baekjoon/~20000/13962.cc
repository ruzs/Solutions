#include <bits/stdc++.h>

using namespace std;

long long st[1 << 20];
int L, R;
void update(int p, int x, int i = 1, int l = L, int r = R) {
	if (l == r) st[i] += x;
	else {
		int m = l + r >> 1;
		if (p <= m) update(p, x, i << 1, l, m);
		else update(p, x, i << 1 | 1, m + 1, r);
		st[i] = st[i << 1] + st[i << 1 | 1];
	}
}
long long query(int s, int e, int i = 1, int l = L, int r = R) {
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return st[i];
	int m = l + r >> 1;
	return query(s, e, i << 1, l, m) + query(s, e, i << 1 | 1, m + 1, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	struct E {
		int r, t, in, out, i;
		bool operator < (E & b) const {
			return r < b.r;
		}
	};
	vector<E> e(n + 1);
	int s;
	for(int i =1; i<=n; ++i) {
		int m;
		cin >> m >> e[i].r >> e[i].t;
		if (~m) g[m].push_back(i);
		else s = i;
		e[i].i = i;
	}
	int ett = 0;
	function<void(int)> dfs = [&](int u) {
		e[u].in = ++ett;
		for(int v : g[u]) dfs(v);
		e[u].out = ett;
	};
	dfs(s);
	L = 1; R = ett;
	sort(e.begin() + 1, e.end());
	vector<long long> ans(n + 1);
	queue<int> q;
	for(int i =1; i<=n; ++i) {
		if (e[i].r != e[i - 1].r) {
			while(q.size()) {
				int a = q.front(); q.pop();
				update(e[a].in, e[a].t);
			}
		}
		ans[e[i].i] = query(e[i].in + 1, e[i].out);
		q.push(i);
	}
	for(int i =1; i<=n; ++i) cout << ans[i] << '\n';
}