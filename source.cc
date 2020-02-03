#include <bits/stdc++.h>

using namespace std;

void solve() {
	int j, n, a[1000];
	cin >> j >> n;
	for(int i =0; i<n; ++i) {
		int b, c;
		cin >> b >> c;
		a[i] = b * c;
	}
	sort(a, a + n);
	int cnt =0;
	for(int i =n-1; ~i; --i) {
		j -= a[i];
		cnt++;
		if (j <= 0) break;
	}
	cout << cnt << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}