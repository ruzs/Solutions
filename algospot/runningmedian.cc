#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, a, b, m = 20090711, s = 0;
	long long x = 1983;
	cin >> n >> a >> b;
	priority_queue<int> l, r;
	l.push(x);
	while(n--) {
		s = (s + l.top()) % m;
		x = (x * a + b) % m;
		
		if (l.top() >= x) l.push(x);
		else r.push(-x);
		if (l.size() > r.size() + 1) r.push(-l.top()), l.pop();
		if (r.size() > l.size()) l.push(-r.top()), r.pop();
	}
	cout << s << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}