#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m, a, s = 0;
	cin >> n >> m >> a;
	s += a;
	for(int i =1; i<n; ++i) {
		cin >> a;
		int x = min(m, a * i) / i;
		s += x;
		m -= x * i;
	}
	cout << s << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}