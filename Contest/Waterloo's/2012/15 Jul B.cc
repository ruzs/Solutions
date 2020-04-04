#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i =0; i<n; ++i) {
		long long x;
		cin >> x;
		auto isprime = [](long long x) {
			if (x < 2) return false;
			if (x % 2 == 0) return x == 2;
			for(long long i = 3; i*i<=x; i += 2) {
				if (x % i == 0) return false;
			}
			return true;
		};
		while(!isprime(x)) x++;
		cout << x << '\n';
	}
}