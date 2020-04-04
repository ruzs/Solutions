#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	long long x =1;
	for(long long i =1; i<=n; ++i) {
		x *= i;
		while(x % 10 == 0) x /= 10;
		x %= 1000000000ll;
	}
	cout << x % 10;
}