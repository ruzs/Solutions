#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	if ((a + b + c + n) % 3) cout << "NO\n";
	else if (a + b + c - max({a, b, c}) + n < max({a, b, c}) * 2) cout << "NO\n";
	else cout << "YES\n";
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}