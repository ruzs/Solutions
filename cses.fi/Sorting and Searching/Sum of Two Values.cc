#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	map<int, vector<int>> mp;
	for(int i =0; i<n; ++i) {
		int a; cin >> a;
		mp[a].push_back(i + 1);
	}
	for(auto & i : mp) {
		if (i.first == x - i.first) {
			if (i.second.size() >= 2) {
				cout << i.second[0] << ' ' << i.second[1];
				return 0;
			}
		}
		else if (mp.count(x - i.first)) {
			cout << i.second[0] << ' ' << mp[x - i.first][0];
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
}