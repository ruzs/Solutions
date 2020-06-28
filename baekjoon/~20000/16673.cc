#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, k, p;
	cin >> c >> k >> p;
	int ans = 0;
	for(int i =1; i<=c; ++i) {
		ans += k * i + p * i * i;
	}
	cout << ans;
}