#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int MAX = 1 << 15;
	vector<int> prime;
	bitset<MAX> v;
	for(int i =3; i<MAX; i+=2) {
		if (v[i]) continue;
		prime.push_back(i);
		for(int j =i*i; j<MAX; j+=i) v[j] = 1;
	}
	int n;
	while(cin >> n) {
		if (!n) break;
		int cnt = 0;
		for(int i : prime) {
			if (i > n / 2) break;
			cnt += binary_search(prime.begin(), prime.end(), n - i);
		}
		cout << cnt << '\n';
	}
}