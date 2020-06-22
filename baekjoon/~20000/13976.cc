#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	cin >> n;
	vector<vector<long long>>
	a = {
		{0, 0, 0, 0, 0, 1},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0}
	},
	r = {
		{1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1},
	};
	auto mul = [](auto & a, auto & b) {
		vector<vector<long long>> r(6, vector<long long>(6));
		for(int i =0; i<6; ++i) for(int j =0; j<6; ++j) for(int k =0; k<6; ++k) {
			r[i][j] += a[i][k] * b[k][j];
			r[i][j] %= 1000000007;
		}
		return r;
	};
	while(n) {
		if (n & 1) r = mul(a, r);
		a = mul(a, a);
		n >>= 1;
	}
	cout << r[5][5];
}