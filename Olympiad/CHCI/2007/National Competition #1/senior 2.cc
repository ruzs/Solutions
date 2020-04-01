#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int MAX = 1e6 + 5;
	vector<int> prime = {2};
	bitset<MAX> v;
	for(int i =3; i*i<MAX; i += 2) {
		if (v[i]) continue;
		prime.push_back(i);
		for(int j = i*i; j<MAX; j += i) v[j] = 1;
	}

	int n;
	cin >> n;
	vector<int> cnt(1000005);
	int y = 0;
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		for(int j : prime) {
			if (j * j > x) break;
			if (x % j == 0) {
				int c = 0;
				while(x % j == 0) x /= j, c ^= 1;
				if (c) {
					cnt[j] ? --y : ++y;
					cnt[j] ^= 1;
				}
			}
		}
		if (x > 1) {
			cnt[x] ? --y : ++y;
			cnt[x] ^= 1;
		}
		if (y) cout << "NE\n";
		else cout << "DA\n";
	}
}