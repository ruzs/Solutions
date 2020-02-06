#include <bits/stdc++.h>

using namespace std;

const int mod = 20091101;

int n, m;
long long a[100005];
vector<int> b[100005];
int d[100005];
int dp(int x) {
	if (x > n) return 0;
	int & ref = d[x];
	if (~ref) return ref;

	ref = dp(x + 1);
	vector<int>::iterator lb = lower_bound(b[a[x] % m].begin(), b[a[x] % m].end(), x);
	if (++lb != b[a[x] % m].end()) ref = max(ref, dp(*lb) + 1);
	return ref;
}
void solve() {
	cin >> n >> m;
	for(int i =0; i<m; ++i) b[i].clear();
	b[0].push_back(0);
	for(int i =1; i<=n; ++i) {
		cin >> a[i];
		a[i] += a[i - 1];
		b[a[i] % m].push_back(i);
	}
	int ans =0;
	for(int i =0; i<m; ++i) {
		int sz = b[i].size();
		ans = (1LL * sz * (sz - 1) / 2 + ans) % mod;
	}
	memset(d, -1, sizeof d);
	cout << ans << ' ' << dp(0) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}