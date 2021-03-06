#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n) {
		if (!n) break;
		int r = n;
		for(int i =2; i*i<=n; ++i) {
			if (n % i == 0) {
				while(n % i == 0) n /= i;
				r -= r / i;
			}
		}
		if (n > 1) r -= r / n;
		cout << r << '\n';
	}
}