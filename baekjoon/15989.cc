#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	int ans = 0;
	for(int i =0; i*3<=n; ++i) {
		ans += (n-i*3) / 2 + 1;
	}
	cout << ans << '\n';
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}