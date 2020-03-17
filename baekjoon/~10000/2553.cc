#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int r = 1;
	for(int i =1; i<=n; ++i) {
		r *= i;
		while(r % 10 == 0) r /= 10;
		r %= 100000;
	}
	cout << r % 10;
}