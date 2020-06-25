#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	auto c = [](int n, int k) {
		long long r = 1;
		for(int i =1; i<=n; ++i) r *= i;
		for(int i =1; i<=k; ++i) r /= i;
		for(int i =1; i<=n-k; ++i) r /= i;
		return r;
	};
	vector<long long> d = {1, 1, 1};
	for(int i =3; i<=20; ++i) {
		long long tmp = 0;
		for(int j =1; j<=i; ++j) {
			tmp += d[j - 1] * d[i - j] * c(i - 1, j - 1);
		}
		d.push_back(tmp / 2);
	}
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) cout << "1\n";
		else cout << d[n] * 2 << '\n';
	}
}