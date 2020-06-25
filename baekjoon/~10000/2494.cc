#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int d[10005][10];
	pair<int, int> f[10005][10];
	memset(d, 64, sizeof d);
	d[0][0] = 0;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<10; ++j) {
			if (d[i][j] < 1e9) {
				int x = (b[i] & 15) - ((a[i] & 15) + j) % 10;
				auto cmp = [&](int ti, int tj, int fi, int fj, int c) {
					if (d[ti][tj] > d[fi][fj] + abs(c)) {
						d[ti][tj] = d[fi][fj] + abs(c);
						f[ti][tj] = {fj, c};
					}
				};
				if (x == 0) {
					cmp(i + 1, j, i, j, 0);
				} else if (x < 0) {
					cmp(i + 1, (j + x + 10) % 10, i, j, (x + 10) % 10);
					cmp(i + 1, j, i, j, x);
				}
				else {
					cmp(i + 1, (j + x) % 10, i, j, x);
					cmp(i + 1, j, i, j, -(10 - x));
				}
			}
		}
	}
	auto j = min_element(&d[n][0], &d[n][10]) - &d[n][0];
	cout << d[n][j] << '\n';
	vector<int> ans;
	for(int i =n; i>0; --i) {
		ans.push_back(f[i][j].second);
		j = f[i][j].first;
	}
	reverse(ans.begin(), ans.end());
	for(int i =0; i<ans.size(); ++i) cout << i + 1 << ' ' << ans[i] << '\n';
}