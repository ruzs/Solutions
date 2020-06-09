#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i =1000; i<10000; ++i) {
		auto f = [](int x, int b) {
			int r =0;
			while(x) r += x % b, x /= b;
			return r;
		};
		int dec = f(i, 10);
		int hex = f(i, 16);
		int twe = f(i, 12);
		if (dec == hex && hex == twe) cout << i << '\n';
	}
}