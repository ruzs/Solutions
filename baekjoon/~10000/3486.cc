#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		auto rev = [](int x) {
			int r = 0;
			while(x) {
				r = r * 10 + x % 10;
				x /= 10;
			}
			return r;
		};
		cout << rev(rev(a) + rev(b)) << '\n';
	}
}