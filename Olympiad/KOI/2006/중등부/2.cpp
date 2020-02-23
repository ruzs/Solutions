#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e4+5;

int n, d[N];
pii p[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =1; i<=n; ++i) {
		cin >> p[i].first >> p[i].second;
		if (p[i].second < 0) p[i].second *= -1;
	}
	sort(p + 1, p + n + 1);
	
	memset(d, 64, sizeof d);
	d[0] = 0;
	for(int i =1; i<=n; ++i) {
		int h = 0;
		for(int j =i; j; --j) {
			h = max(h, p[j].second);
			d[i] = min(d[i], max(h * 2, p[i].first - p[j].first) + d[j - 1]);
		}
	}
	cout << d[n];
}
