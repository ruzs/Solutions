#include <bits/stdc++.h>
using namespace std;

int n, q, c, y, x, a[2][100002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	while(q--) {
		cin >> y >> x;
		int connect = a[y%2][x - 1] + a[y%2][x] + a[y%2][x + 1];
		if (a[y - 1][x] ^= 1) c += connect;
		else c -= connect;

		if (c != 0) cout << "No\n";
		else cout << "Yes\n";
	}
}