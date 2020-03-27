#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> a(n + 1);
	long long x = 0;
	for(int i =1; i<=n; ++i) cin >> a[i], x ^= a[i];
	a.push_back(x);
	a.insert(a.end(), a.begin() + 1, a.end());
	partial_sum(a.begin(), a.end(), a.begin(), [](auto a, auto b) { return a ^ b; });
	int m;
	cin >> m;
	while(m--) {
		long long x, y;
		cin >> x >> y;
		x = (x - 1) % (n + 1) + 1;
		y = (y - 1) % (n + 1) + n + 2;
		cout << (a[y] ^ a[x - 1]) << '\n';
	}
}