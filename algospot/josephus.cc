#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for(int i =1; i<=n; ++i) q.push(i);
	while(q.size() > 2) {
		q.pop();
		for(int i =1; i<k; ++i) q.push(q.front()), q.pop();
	}
	int a = q.front(); q.pop();
	int b = q.front();
	cout << min(a, b) << ' ' << max(a, b) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}