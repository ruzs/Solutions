#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, l, k;
	cin >> n >> m >> l >> k;
	vector<pair<int, int>> pos(k);
	for(auto & i : pos) cin >> i.first >> i.second;
	int mx = 0;
	for(auto & i : pos) {
		for(auto & j : pos) {
			if (abs(i.first - j.first) > l || abs(i.second - j.second) > l) continue;
			int x = min(i.first, j.first);
			int y=  min(i.second, j.second);
			int cnt = 0;
			for(auto & h : pos) {
				if (x <= h.first && h.first <= x + l
				&& y <= h.second && h.second <= y + l) cnt++;
			}
			mx = max(mx, cnt);
		}
	}
	cout << k - mx;
}