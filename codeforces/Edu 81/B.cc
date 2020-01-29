#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x, a[100001]{};
	string s;
	cin >> n >> x >> s;
	for(int i =0; i<n; ++i) {
		a[i + 1] = a[i] + (s[i] == '0' ? 1 : -1);
	}
	if (a[n] == 0) {
		for(int i =0; i<=n; ++i) if (a[i] == x) {
			cout << "-1\n";
			return;
		}
		cout << "0\n";
		return;
	}
	int cnt = 0;
	for(int i =1; i<=n; ++i) {
		if ((a[n] < 0 && x > a[i]) || (a[n] > 0 && x < a[i])) continue;
		if ((x - a[i]) % a[n] == 0) cnt++;
	}
	cout << cnt + (x == 0) << '\n';
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}