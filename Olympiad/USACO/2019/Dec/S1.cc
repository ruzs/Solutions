#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	auto pos = [n](int x) {
		int r = x;
		r -= x / 3;
		r -= x / 5;
		r += x / 15;
		return r < n;
	};
	int ans = 0, j = 1e9;
	while(j /= 2) {
		while(pos(ans + j)) ans += j;
	}
	cout << ans + 1;
}