#include <bits/stdc++.h>

using namespace std;

int n, m, a[501][501];

int main() {
	cin >> n >> m;
	int sq = (int)(sqrt((double)(n*m))+0.5);
	if (sq*sq != n*m || m > n) return cout << -1, 0;
	m = 0;
	for(int i =1; i<=n; ++i) {
		for(int j =sq*(i-1)+1; j<=sq*i; ++j) {
			a[i][j%n ? j%n : n] = 1;
			m++;
		}
	}
	cout << m << '\n';
	for(int i =1; i<=n; ++i) {
		for(int j =1; j<=n; ++j) {
			if (a[i][j]) cout << i << ' ' << j << '\n';
		}
	}
}
// #include <bits/stdc++.h>

// using namespace std;

// using vi = vector<int>;
// using matrix = vector<vi>;
// matrix mul(matrix& a) {
// 	int n =a.size();
// 	matrix r(n, vi(n, 0));
// 	for(int i =0; i<n; ++i)
// 		for(int j =0; j<n; ++j)
// 			for(int k =0; k<n; ++k)
// 				r[i][j] += a[i][k] * a[k][j];
// 	return r;
// }
// int main() {
// 	int n, m; cin >> n >> m;
// 	matrix a(n, vi(n));
// 	for(int i =0; i<m; ++i) {
// 		int r, c; cin >> r >> c;
// 		a[r - 1][c - 1] = 1;
// 	}
// 	auto r = mul(a);
// 	for(auto & i : r) {
// 		for(int j : i) cout << j << ' ';
// 		cout << endl;
// 	}
// }