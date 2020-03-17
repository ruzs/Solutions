#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int cnt = 0;
	auto f = [k](int x) {
		return x / 10 == k || x % 10 == k;
	};
	for(int h =0; h<=n; ++h) {
		for(int m =0; m<60; ++m) {
			for(int s =0; s<60; ++s) {
				if (f(s) || f(m) || f(h)) cnt++;
			}
		}
	}
	cout << cnt;
}