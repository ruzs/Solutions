#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	struct prime {
		vector<int> p;
		bitset<5000005> np;
		prime(int max_n) : p({2}) {
			int i, j, k;
			for (i = 3; i * i <= max_n; i += 2) {
				if (np[i >> 1]) continue;
				p.push_back(i);
				for (j = i * i, k = i + i; j <= max_n; j += k)
					np[j >> 1] = 1;
			}
			while (i <= max_n) {
				if (!np[i >> 1]) p.push_back(i);
				i += 2;
			}
		}
		auto begin() { return p.begin(); }
		auto end() { return p.end(); }
	} p(n);
	vector<int> d(n + 1, 0);
	d[0] = 1;
	for(int j : p) {
		for(int i =j; i<=n; ++i) {
			if (d[i - j]) {
				d[i] += d[i - j];
				d[i] %= 123456789;
			}
		}
	}
	cout << d[n];
}