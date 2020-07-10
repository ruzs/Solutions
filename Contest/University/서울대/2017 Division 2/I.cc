#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	for(int i =2; i*i<=n; ++i) {
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
	}
	if (n > 1) cnt++;
	if (cnt == 1) cout << 0;
	else cout << 32 - __builtin_clz(cnt - 1);
}