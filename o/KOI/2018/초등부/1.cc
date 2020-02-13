#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a, mn = 1e3, mx = 0;
	cin >> n;
	while(n--) {
		cin >> a;
		if (mn > a) mn = a;
		if (mx < a) mx = a;
	}
	cout << mx - mn;
}