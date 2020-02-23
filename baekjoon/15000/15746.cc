#include <bits/stdc++.h>

using namespace std;

auto fio = ios::sync_with_stdio(0);

vector<int> g[100005];
int l[100005], c[100005], p[100005], leaves;
long long d[100005], bessie;
int dfs(int a, long long acc) {
	if (g[a].empty()) return bessie += acc - 1, leaves++, 1;
	for(int b : g[a]) {
		l[a] += dfs(b, acc + c[b] + 1);
	}
	return l[a];
}
long long dp(int a) {
	auto & ref = d[a];
	if (~ref) return ref;
	ref = dp(p[a]) - l[a] * (c[a] + 1) + (leaves - l[a]) * 3;
	for(int b : g[a]) {
		dp(b);
	}
	return ref;
}
int main() {
	int n, m, k;
	string s;

	cin >> n;
	for(int i =1; i<=n; ++i) {
		cin >> s >> m;
		c[i] = s.size();
		while(m--) {
			cin >> k;
			g[i].push_back(k);
			p[k] = i;
		}
	}
	dfs(1, 0);
	memset(d, -1, sizeof d);
	d[1] = bessie;
	long long ans = 1e18;
	for(int i =1; i<=n; ++i) {
		if (g[i].empty()) continue;
		ans = min(ans, dp(i));
	}
	cout << ans;
}