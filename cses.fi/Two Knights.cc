#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	for(long long i =1; i<=n; ++i) {
		long long ans = i*i * (i*i - 1) / 2;
		if (i == 3) ans -= 8;
		else if (i > 3) {
			for(int j =1; j<=i; ++j) {
				if (j == 1 || j == i) ans -= 2 * i - 3;
				else if (j == 2 || j == i - 1) ans -= 3 * i - 5;
				else ans -= 4 * i - 6;
			}
		}
		cout << ans << '\n';
	}
}