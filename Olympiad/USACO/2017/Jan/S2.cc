#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> p = {{0, 0, 0}};
	for(int i =0; i<n; ++i) {
		char c; cin >> c;
		p.push_back(p.back());
		if (c == 'H') {
			p.back()[0]++;
		} else if (c == 'P') {
			p.back()[1]++;
		} else {
			p.back()[2]++;
		}
	}
	int ans = 0;
	for(int i =0; i<n; ++i) {
		auto f = [&](int s, int e) {
			int H = p[e][0] - p[s][0];
			int P = p[e][1] - p[s][1];
			int S = p[e][2] - p[s][2];
			return max({H, P, S});
		};
		ans = max(ans, f(0, i) + f(i, n));
	}
	cout << ans;
}