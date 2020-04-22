#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> prime = {2};
	bitset<32000> np;

	for(int i = 3; i<32000; i += 2) {
		if (!np[i]) {
			prime.push_back(i);
			for(int j = i * i; j<32000; j += i) np[j] = 1;
		}
	}

	int n, m;
	vector<int> a, b;

	cin >> n;
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		for(int p : prime) {
			if (p * p > x) break;
			while(x % p == 0) {
				a.push_back(p);
				x /= p;
			}
		}
		if (x > 1) a.push_back(x);
	}

	cin >> m;
	for(int i =0; i<m; ++i) {
		int x; cin >> x;
		for(int p : prime) {
			if (p * p > x) break;
			while(x % p == 0) {
				b.push_back(p);
				x /= p;
			}
		}
		if (x > 1) b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> intersect(a.size());
	intersect.resize(set_intersection(a.begin(), a.end(), b.begin(), b.end(), intersect.begin()) - intersect.begin());

	long long ans = 1, gt = 0;
	for(int i : intersect) {
		ans *= i;
		if (ans > 999999999) {
			ans %= 1000000000;
			gt = 1;
		}
	}
	if (gt) {
		cout.width(9);
		cout.fill('0');
	}
	cout << ans;
}