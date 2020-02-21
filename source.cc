#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
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
=======
void solve() {
	int p, q, r, a, b, c, d;
	cin >> p >> q >> a >> b >> c >> d;
	r = q / c * d;
	int k = (r - p) / (a + b);
	int ans = 0;
	for(int i =k - 5000; i < k + 5000; ++i) {
		ans = max(ans, min(p + a * i, r - b * i));
	}
	cout << ans << '\n';
>>>>>>> ef72632469cae9f198d75202044b6e0cfa8dcd9e
}
int main() {
	int n, m, k;
	string s;

<<<<<<< HEAD
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
=======
	int T, t =0; cin >> T;
	while(++t <= T) solve();
>>>>>>> ef72632469cae9f198d75202044b6e0cfa8dcd9e
}