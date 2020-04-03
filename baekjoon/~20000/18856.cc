#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cout << n << '\n';
	int i;
	for(i =1; i<n; ++i) cout << i << ' ';
	auto isprime = [](int x) {
		for(int i =2; i*i<=x; ++i) {
			if (x % i == 0) return false;
		}
		return true;
	};
	while(!isprime(i)) i++;
	cout << i;
}