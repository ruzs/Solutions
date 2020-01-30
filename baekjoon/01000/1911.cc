#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	pair<int, int> a[10005];
	cin >> n >> m;
	for(int i =0; i<n; ++i) cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	int cnt =0, l =0;
	for(int i =0; i<n; ++i) {
		int x = a[i].second - max(l, a[i].first);
		int y = (x + m - 1) / m;
		cnt += y;
		l = max(l, a[i].first) + y * m;
	}
	cout << cnt;
}