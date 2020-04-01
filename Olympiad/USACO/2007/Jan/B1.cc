#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int MAX = 4e6;
	bitset<MAX> v;
	for(int i =3; i*i<MAX; i += 2) {
		if (v[i]) continue;
		for(int j =i*i; j<MAX; j += i) v[j] = 1;
	}
	vector<int> prime = {2};
	for(int i =3; i<MAX; i += 2) if (!v[i]) prime.push_back(i);

	int a, b, c;
	cin >> a >> b >> c;
	auto lb = lower_bound(prime.begin(), prime.end(), a);
	auto ub = upper_bound(prime.begin(), prime.end(), b);
	int cnt = 0;
	while(lb != ub) {
		int p = *lb;
		bool ok = 0;
		while(p) {
			if (p % 10 == c) {
				ok = 1;
				break;
			}
			p /= 10;
		}
		if (ok) cnt++;
		lb++;
	}
	cout << cnt;
}