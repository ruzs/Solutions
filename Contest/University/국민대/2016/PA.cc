#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int ans = 0;
	auto reverse = [&](int a) {
		int r = 0;
		while(a) r = r * 10 + a % 10, a /= 10;
		return r;
	};
	for(int i =1; i<=k; ++i) {
		ans = max(ans, reverse(n * i));
	}
	cout << ans;
}