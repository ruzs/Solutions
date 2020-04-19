#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v), end(v)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(100005), bkt[320];
	for(int i =0; i<n; ++i) {
		cin >> a[i];
		bkt[i / 320].push_back(a[i]);
	}
	for(int i =0; i<320; ++i)
		sort(all(bkt[i]));
	int m;
	cin >> m;
	while(m--) {
		int w, x, y, z;
		cin >> w;
		if (w == 1) {
			cin >> x >> y >> z;
			x--; y--;
			int cnt = 0;
			if (x / 320 == y / 320) {
				for(int i = x; i<=y; ++i)
					if (a[i] > z) cnt++;
			} else {
				for(int i =(x/320+1)*320-1; i>=x; --i)
					if (a[i] > z) cnt++;
				for(int i = x / 320 + 1; i<y / 320; ++i)
					cnt += bkt[i].end() - upper_bound(all(bkt[i]), z);
				for(int i =y/320*320; i<=y; ++i)
					if (a[i] > z) cnt++;
			}
			cout << cnt << '\n';
		} else {
			cin >> x >> y;
			x--;
			auto & b = bkt[x / 320];
			int i = lower_bound(all(b), a[x]) - b.begin();
			a[x] = y;
			b[i] = y;
			while(i + 1 < b.size() && b[i] > b[i + 1]) {
				swap(b[i], b[i + 1]);
				i++;
			}
			while(i > 0 && b[i - 1] > b[i]) {
				swap(b[i - 1], b[i]);
				i--;
			}
		}
	}
}