#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		ans += abs(x);
	}
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		ans += abs(x);
	}
	cout << ans;
}