#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> d(n + 1);
	for(int i =1; i<=n; ++i) {
		if (i - 1 >= 0) d[i] |= !d[i - 1];
		if (i - 3 >= 0) d[i] |= !d[i - 3];
		if (i - 4 >= 0) d[i] |= !d[i - 4];
	}
	cout << (d[n] ? "SK" : "CY");
}