#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, p = 0, mn1 = 1e9, mn2 = 1e9;
	cin >> n;
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		if (x == -1) p = 1;
		else if (p) {
			if (mn2 > x) mn2 = x;
		}
		else {
			if (mn1 > x) mn1 = x;
		}
	}
	cout << mn1 + mn2;
}