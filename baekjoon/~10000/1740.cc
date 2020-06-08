#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;
	long long ans = 0, x = 1;
	while(n) {
		if (n & 1) ans += x;
		x *= 3;
		n >>= 1;
	}
	cout << ans;
}