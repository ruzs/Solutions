#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int mod = 1e9 + 7;

	int n, m;
	cin >> n >> m;

	vector<vector<long long>> r(m, vector<long long>(m)), odd = r, even = r;
	for(int i =0; i<m; ++i) {
		r[i][i] = 1;
		odd[i][i] = 1;
		if (i > 0) {
			odd[i][i - 1] = 1;
			even[i][i - 1] = 1;
		}
		if (i + 1 < m) {
			odd[i][i + 1] = 1;
			even[i][i + 1] = 1;
		}
	}
	auto mul = [m, mod](auto& a, auto& b) {
		vector<vector<long long>> r(m, vector<long long>(m));
		for(int i =0; i<m; ++i) for(int j =0; j<m; ++j) for(int k =0; k<m; ++k) {
			r[i][j] += a[i][k] * b[k][j];
			r[i][j] %= mod;
		}
		return r;
	};
	int e = (n - 1) / 2;
	odd = mul(odd, even);
	while(e) {
		if (e & 1) r = mul(r, odd);
		odd = mul(odd, odd);
		e >>= 1;
	}
	if (n % 2 == 0) r = mul(even, r);
	long long ans = 0;
	for(int i =0; i<m; ++i) {
		for(int j =0; j<m; ++j) {
			ans = (ans + r[i][j]) % mod;
		}
	}
	cout << ans;
}