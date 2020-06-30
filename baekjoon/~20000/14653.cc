#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	bool read[26]{};
	vector<pair<int, int>> v(m + 1);
	for(int i =1; i<=m; ++i) {
		int r;
		char x;
		cin >> r >> x;
		v[i] = {r, x - 'A'};
		if (i == k) {
			if (r == 0) {
				cout << -1;
				return 0;
			}
			for(int j =i; j > 0 && v[j].first == r; --j)
				read[v[j].second] = 1;
		}
		if (i >= k) read[x - 'A'] = 1;
	}
	read[0] = 1;
	for(int i =0; i<n; ++i)
		if (!read[i]) cout << static_cast<char>(i + 'A') << ' ';
}