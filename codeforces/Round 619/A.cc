#include <bits/stdc++.h>

using namespace std;

void solve() {
	string a, b, c;
	cin >> a >> b >> c;
	for(int i =0; i<a.size(); ++i) {
		if (a[i] == c[i] || b[i] == c[i]);
		else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}