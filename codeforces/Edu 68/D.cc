#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	if (k % 3) {
		cout << (n % 3 ? "Alice" : "Bob") << '\n';
	}
	else {
		n %= k + 1;
		cout << (n % 3 || n == k ? "Alice" : "Bob") << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}