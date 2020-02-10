#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, a, s = 0, cnt = 0;
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> a;
		s += a;
		if (!a) cnt++, s++;
	}
	cout << (s ? cnt : cnt + 1) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}