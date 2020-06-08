#include <bits/stdc++.h>

using namespace std;

using digits = vector<int>;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	function<digits(int, int, int)> bf = [&](int n, int b, int c) {
		if (n < 10) {
			digits r(10);
			for(int i =1; i<=n; ++i) r[i] = 1;
			return r;
		}
		if (b > n) return bf(n, b / 10, c - 1);
		digits r = bf(b - 1, b / 10, c - 1);

		int f = 1;
		while (b >= 1) {
			for(int i =f; i<n/b; ++i) {
				r[i] += b;
				for(int j =0; j<10; ++j) {
					r[j] += b / 10 * c;
				}
			}
			r[n/b] += n % b + 1;
			n %= b; b /= 10; c--;
			f = 0;
		}
		return r;
	};
	for(int i : bf(n, 1000000000, 9)) cout << i << ' ';
}