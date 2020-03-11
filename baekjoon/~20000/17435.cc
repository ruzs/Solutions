#include <bits/stdc++.h>

using namespace std;

int f[200005][20];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i =1; i<=n; ++i) {
		cin >> f[i][0];
	}
	for(int j =1; j<20; ++j) {
		for(int i =1; i<=n; ++i) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	cin >> n;
	while(n--) {
		int a, b;
		cin >> a >> b;
		for(int j = 19; ~j; --j) {
			if (a >= 1 << j) b = f[b][j], a -= 1 << j;
		}
		cout << b << '\n';
	}
}