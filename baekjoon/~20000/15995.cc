#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, m;
	cin >> a >> m;
	for(int i =1; i<m; ++i) {
		if (a * i % m == 1) {
			cout << i;
			return 0;
		}
	}
}