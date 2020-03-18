#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m = 0;
	cin >> n;
	vector<int> a(n);
	for(int i =0; i<n; ++i) cin >> a[i], m += a[i];

	vector<long long> d(m / 2 + 1, 0);
	d[0] = 1;
	int x = 0;
	for(int j : a) {
		for(int i =m/2; i; --i) {
			if (i < j) break;
			if (d[i - j]) {
				d[i] += d[i - j];
				d[i] %= 1000000;
				x = max(x, i);
			}
		}
	}
	cout << m - x - x << '\n' << d[x];
}