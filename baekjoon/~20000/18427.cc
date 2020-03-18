#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, h;
	cin >> n >> m >> h;
	cin.ignore();
	vector<vector<int>> a(n);
	for(int i =0; i<n; ++i) {
		string s;
		getline(cin, s);
		int x = 0;
		for(char c : s) {
			if (c == ' ') a[i].push_back(x), x = 0;
			else x = x * 10 + (c & 15);
		}
		if (x) a[i].push_back(x);
		sort(a[i].begin(), a[i].end());
	}
	vector<int> d(h + 1, 0);
	d[0] = 1;
	for(auto & i : a) {
		for(int k =h; k; --k) {
			for(int j : i) {
				if (k < j) break;
				d[k] += d[k - j];
				d[k] %= 10007;
			}
		}
	}
	cout << d[h];
}