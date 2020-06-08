#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a[5];
	for(int i =0; i<5; ++i) cin >> a[i];
	sort(a, a + 5);
	auto lcm = [](int a, int b) {
		return a / __gcd(a, b) * b;
	};
	int ans = 1e9;
	do {
		ans = min(ans, lcm(a[0], lcm(a[1], a[2])));
	} while(next_permutation(a, a + 5));
	cout << ans;
}