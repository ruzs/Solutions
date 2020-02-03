#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, a;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a, pq.push(a);
	int ans =0;
	while(pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		ans += a + b;
		pq.push(a + b);
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	while(T--) solve();
}