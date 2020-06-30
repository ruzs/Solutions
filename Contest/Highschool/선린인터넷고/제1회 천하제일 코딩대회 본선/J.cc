#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int mx = 0, h = 0, cnt = 0;
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		if (h < x) {
			mx = max(mx, cnt);
			cnt = 0;
			h = x;
		} else {
			cnt++;
		}
	}
	cout << max(mx, cnt);
}