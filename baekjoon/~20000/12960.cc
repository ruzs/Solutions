#include <bits/stdc++.h>

using namespace std;

template <int D, typename T> struct matrix : public vector<matrix<D - 1, T>> {
	template <typename... Args>
	matrix(int n = 0, Args... args)
		: vector<matrix<D - 1, T>>(n, matrix<D - 1, T>(args...)) {}
};
template <typename T> struct matrix<1, T> : public vector<T> {
	matrix(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(string & i : a) cin >> i;

	matrix<3, int> d(n, m, 1 << n + 1, -1);
	function<int(int, int, int)> dp = [&](int y, int x, int msk) {
		if (x == m) return 0;
		if (y < 0) return dp(n - 1, x + 1, msk);
		int & ref = d[y][x][msk];
		if (~ref) return ref;

		if (a[y][x] != '.') {
			ref = dp(y - 1, x, msk >> 1 | 1 << n);
		} else {
			ref = dp(y - 1, x, msk >> 1);
			if (y + x & 1) {
				if (y + 1 < n && (msk & 3 ^ 3) == 3)
					ref = max(ref, 1 + dp(y - 1, x, msk >> 1 | 1 | 1 << n));
				if (y - 1 >= 0 && (msk >> 1 & 3 ^ 3) == 3)
					ref = max(ref, 1 + dp(y - 1, x, msk >> 1 | 3 | 1 << n));
			} else {
				if (msk >> 1 & 1 ^ 1) {
					if (y + 1 < n && msk >> n & 1 ^ 1)
						ref = max(ref, 1 + dp(y - 1, x, msk >> 1 | 1 | 3 << n - 1));
					if (y - 1 >= 0 && a[y - 1][x] == '.')
						ref = max(ref, 1 + dp(y - 2, x, msk >> 2 | 3 << n - 1));
				}
			}
		}
		return ref;
	};
	cout << dp(n - 1, 0, (1 << n + 1) - 1);
}