#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, ha;
	cin >> n >> ha;
	vector<tuple<int, int, int>> v;
	for(int i =0; i<n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v.emplace_back(a, b, c);
	}
	auto valid = [&](long long x) {
		long long atk = ha, hp = x;
		for(auto &[a, b, c] : v) {
			if (a == 1) {
				long long turn = (c - 1) / atk;
				if (hp <= turn * b) return false;
				hp -= turn * b;
			} else {
				atk += b;
				hp = min(x, hp + c);
			}
		}
		return true;
	};
	long long ans = 1e18, j = 1e18;
	while(j /= 2) {
		while(valid(ans - j)) ans -= j;
	}
	cout << ans;
}