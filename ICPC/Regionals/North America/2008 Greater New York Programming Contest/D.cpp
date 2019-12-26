#include <bits/stdc++.h>
using namespace std;

int t, n, d[1001];
int dp(int x) {
	if (x < 2) return 1;
	int & ref = d[x];
	if (ref) return ref;
	x /= 2;
	for(int i =0; i<=x; ++i) {
		ref += dp(i);
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
		cin >> n;
		cout << dp(n) << '\n';
	}
}
