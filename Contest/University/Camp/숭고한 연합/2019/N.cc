#include <bits/stdc++.h>

using namespace std;

using matrix = vector<vector<int>>;

matrix mul(const matrix & a, const matrix & b, const int mod = 1e9 + 7)
{
	matrix r(a.size(), vector<int>(b[0].size()));
	for(int i =0; i<a.size(); ++i)
		for(int j =0; j<b[0].size(); ++j)
			for(int k =0; k<b.size(); ++k)
				r[i][j] = (r[i][j] + (long long)a[i][k] * b[k][j] % mod) % mod;
	return r;
}

matrix pow(matrix a, int e, const int mod = 1e9 + 7)
{
	matrix r(a.size(), vector<int>(a[0].size()));
	for(int i =0; i<a.size(); ++i) r[i][i] = 1;
	while (e > 0) {
		if (e & 1) r = mul(r, a);
		a = mul(a, a);
		e /= 2;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, d;
	cin >> t >> n >> d;
	vector<matrix> g(t, matrix(n, vector<int>(n)));
	matrix all(n, vector<int>(n));
	for(int i =0; i<n; ++i) all[i][i] = 1;
	for(int i =0; i<t; ++i) {
		int m;
		cin >> m;
		while (m--) {
			int a, b, c;
			cin >> a >> b >> c;
			g[i][a - 1][b - 1] = c;
		}
		all = mul(all, g[i]);
	}
	auto r = pow(all, d / t);
	for(int i =0; i<d%t; ++i)
		r = mul(r, g[i]);
	for(int i =0; i<n; ++i) {
		for(int j =0; j<n; ++j)
			cout << r[i][j] << ' ';
		cout << '\n';
	}
}