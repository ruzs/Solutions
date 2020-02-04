#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	cout << ((a + b) % 3 || min(a, b) * 2 < max(a, b) ? "NO" : "YES") << '\n';
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}