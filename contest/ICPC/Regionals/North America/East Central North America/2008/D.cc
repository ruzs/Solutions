#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d = 0;
	pair<int, int> a[100];
	while(cin >> n) {
		if (!n) break;
		for(int i =0; i<n; ++i) {
			int s, e;
			cin >> s >> e;
			a[i] = { s - 8 << 1, e - 8 << 1 };
		}
		int cnt = 0;
		for(int i =31; ~i; --i) {
			int idx = -1, l = -1;
			for(int j =0; j<n; ++j) {
				if (a[j].first <= i && i < a[j].second && l < a[j].first) {
					idx = j;
					l = a[j].first;
				}
			}
			if (~idx) cnt++, a[idx].first = 32;
		}
		cout << "On day " << ++d << " Emma can attend as many as " << cnt << " parties.\n";
	}
}