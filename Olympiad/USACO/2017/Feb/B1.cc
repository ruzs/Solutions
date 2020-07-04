#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0, cow[11];
	memset(cow, -1, sizeof cow);
	while(n--) {
		int x, y;
		cin >> x >> y;
		if (cow[x] == -1) cow[x] = y;
		else if (cow[x] != y) cnt++;
		cow[x] = y;
	}
	cout << cnt;
}