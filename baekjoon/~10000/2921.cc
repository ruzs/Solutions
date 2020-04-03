#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for(int i =1; i<=n; ++i) {
		for(int j =0; j<=i; ++j) ans += i + j;
	}
	cout << ans;
}