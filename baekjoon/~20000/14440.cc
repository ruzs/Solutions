#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, a0, a1, n;
	cin >> x >> y >> a0 >> a1 >> n;
	vector<vector<int>> a = {{x, y}, {1, 0}}, r = {{1, 0}, {0, 1}};
	auto mul = [](auto & a, auto & b) {
		vector<vector<int>> r(2, vector<int>(2));
		for(int i =0; i<2; ++i) for(int j =0; j<2; ++j) for(int k =0; k<2; ++k) {
			r[i][j] += a[i][k] * b[k][j];
			r[i][j] %= 100;
		}
		return r;
	};
	cout.width(2);
	cout.fill('0');
	cout << fixed;
	if (n == 0) cout << a0;
	else if (n == 1) cout << a1;
	else {
		while(n) {
			if (n & 1) r = mul(r, a);
			a = mul(a, a);
			n >>= 1;
		}
		cout << (r[1][0] * a1 + r[1][1] * a0) % 100;
	}
}