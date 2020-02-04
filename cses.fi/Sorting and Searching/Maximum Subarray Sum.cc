#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, a, s = 0, ans = -1e18;
	cin >> n;
	while(n--) {
		cin >> a;
		s += a;
		if (ans < s) ans = s;
		if (s < 0) s = 0;
	}
	cout << ans;
}