#include <bits/stdc++.h>
using namespace std;

int n, m;
struct goods {
	string s;
	int v, n;
} a[100];
vector<int> ans;

int d[100][1001];
int dp(int i, int r) {
	if (r < 0) return -1e9;
	if (r == 0 || i == n) return 0;

	int & ref = d[i][r];
	if (ref != -1) return ref;

	return ref = max(dp(i + 1, r), dp(i + 1, r - a[i].v) + a[i].n);
}
void solve() {
	cin >> n >> m;
	for(int i =0; i<n; ++i) cin >> a[i].s >> a[i].v >> a[i].n;
	memset(d, -1, sizeof d);
	cout << dp(0, m) << ' ';
	int i = 0, r = m, s = d[0][m];
	ans.clear();
	while(r > 0 && i < n) {
		if (s != d[i + 1][r]) {
			r -= a[i].v;
			s -= a[i].n;
			if (s >= 0) ans.push_back(i);
		}
		i++;
	}
	cout << ans.size() << '\n';
	for(int i : ans) {
		cout << a[i].s << '\n';
	}
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}
