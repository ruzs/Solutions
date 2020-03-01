#include <bits/stdc++.h>
using namespace std;

auto factors(int x) {
	set<int> r;
	for(int i =2; i*i<=x; ++i) {
		if (x % i == 0) {
			r.insert(i);
			r.insert(x / i);
		}
	}
	return r;
}
int d[45000];
int dp(int x) {
	if (d[x] < 1e9) return d[x];
	auto fac = factors(x);
	int cnt = 0;
	for(int i : fac) {
		cnt += dp(i);
	}
	return d[x] = 1 - cnt;
}
bool valid(int x, int n) {
	int cnt = 0;
	for(int i =2; i*i<=x; ++i) {
		cnt += x / (i*i) * dp(i);
	}
	return x - cnt < n;
}
int main() {
	memset(d, 64, sizeof d);
	int n; cin >> n;
	int ans = 0, j = 1e9;
	for(; j; j /= 2) {
		while(valid(ans + j, n)) ans += j;
	}
	cout << ans + 1;
}
