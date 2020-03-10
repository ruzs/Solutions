#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	
	struct prime {
		vector<int> p;
		bitset<560> np;
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

		bool isPrime(int x) {
			return x % 2 == 0 ? x == 2 : !np[x >> 1];
		}
	} p(1121);
	int d[15][1121]{};
	d[0][0] = 1;
	for(int k : p) {
		for(int i =14; i; --i) {
			for(int j =k; j<1121; ++j) {
				d[i][j] += d[i - 1][j - k];
			}
		}
	}
	while(t--) {
		int n, k;
		cin >> n >> k;
		cout << d[k][n] << '\n';
	}
}