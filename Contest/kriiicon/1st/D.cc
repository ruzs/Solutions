#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	tuple<int, int, int> p[900];
	for(int i =0; i<3*n; ++i) {
		int y, x;
		cin >> y >> x;
		p[i] = {y, x, i + 1};
	}
	sort(p, p + 3*n);
	for(int i =0; i<n*3; i+=3) {
		cout << get<2>(p[i]) << ' '
			<< get<2>(p[i + 1]) << ' '
			<< get<2>(p[i + 2]) << '\n';
	}
}