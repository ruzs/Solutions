#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	const int mod = 1e9 + 7;
	using matrix = vector<vector<long long>>;
	auto mul = [](auto a, auto b) {
		matrix r(a.size(), vector<long long>(b.size()));
		for(int i =0; i<a.size(); ++i)
			for(int j =0; j<b.size(); ++j)
				for(int k =0; k<b[0].size(); ++k)
					r[i][k] = (r[i][k] + a[i][j] * b[j][k]) % mod;
		return r;
	};
	matrix a(n, vector<long long>(n)), r = a;
	for(int i =0; i<n; ++i) r[i][i] = 1;
	for(int i =0; i<n; ++i)
		for(int j =0; j<n; ++j)
			cin >> a[i][j];
	
	for (; k > 0; k >>= 1, a = mul(a, a))
		if (k & 1) r = mul(r, a);

	int ans = 0;
	for(int i =0; i<n; ++i)
		for(int j =0; j<n; ++j)
			ans = (ans + r[i][j]) % mod;
	cout << ans;
}