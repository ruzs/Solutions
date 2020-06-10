#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bitset<15> bs[10] = { 31599, 4681, 29671, 29647, 23497, 31183, 31215, 29257, 31727, 31695 };
	int n;
	cin >> n;
	vector<string> s(5);
	for(int i =0; i<5; ++i) cin >> s[i];
	vector<vector<int>> a(n);
	for(int i =0; i<n; ++i) {
		int x = 0;
		for(int j =0; j<5; ++j) for(int k =0; k<3; ++k) {
			x <<= 1;
			if (s[j][4 * i + k] == '#') x |= 1;
		}
		bitset<15> bx = x;
		for(int j =0; j<10; ++j) {
			if ((bx & bs[j]) == bx) a[i].push_back(j);
		}
	}
	long long u = 0, m = 1;
	for(int i =0; i<n; ++i) m *= a[i].size();
	for(int i =0; i<n; ++i) {
		for(int j : a[i]) {
			u += j * pow(10, n - i - 1) * (m / a[i].size());
		}
	}
	if (!u) cout << -1;
	else {
		cout.precision(20);
		cout << fixed << (double)u / m;
	}
}