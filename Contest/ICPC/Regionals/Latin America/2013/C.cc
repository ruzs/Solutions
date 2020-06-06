#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;
	a--;
	long long sum = 0;
	for(long long i =60; i>=0; --i) {
		if (b >= (1ll << i)) {
			b -= (1ll << i);
			sum += i * (1ll << i - 1) + b + 1;
		}
		if (a >= (1ll << i)) {
			a -= (1ll << i);
			sum -= i * (1ll << i - 1) + a + 1;
		}
	}
	cout << sum;
}