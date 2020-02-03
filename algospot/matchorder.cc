#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x;
	priority_queue<int, vector<int>, greater<int>> a, b;
	cin >> n;
	for(int i =0; i<n; ++i) cin >> x, a.push(x);
	for(int i =0; i<n; ++i) cin >> x, b.push(x);
	int ans =0;
	while(a.size()) {
		while(b.size() && a.top() > b.top()) b.pop();
		if (b.size()) ans++, b.pop();
		a.pop();
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--) solve();
}