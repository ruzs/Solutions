#include <bits/stdc++.h>

using namespace std;

int diff(int x, vector<int>& a) {
	int mx = 0;
	for(int i =1; i<a.size(); ++i) {
		mx = max(mx, abs((~a[i] ? a[i] : x) - (~a[i - 1] ? a[i - 1] : x)));
	}
	return mx;
}
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	
	int lo = 0, hi = 1e9;
	while(lo + 1 < hi) {
		int md = lo + hi >> 1;
		if (diff(lo + md >> 1, a) < diff(md + hi >> 1, a)) hi = md;
		else lo = md;
	}
	int mx = 0;
	for(int i =1; i<a.size(); ++i) mx = max(mx, abs((~a[i - 1] ? a[i - 1] : lo) - (~a[i] ? a[i] : lo)));
	cout << mx << ' ' << lo << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}