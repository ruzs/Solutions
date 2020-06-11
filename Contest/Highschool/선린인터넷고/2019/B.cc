#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<long long, int>> a(n);
	for(auto & i : a) cin >> i.first;
	for(auto & i : a) cin >> i.second;
	long long sum = 0;
	for(auto & i : a) if (i.first < i.second) {
		long long d = (i.second - i.first + 29) / 30;
		sum += d;
		i.first += d * 30;
	}
	sort(a.begin(), a.end(), [](auto& a, auto& b) {
		return a.second < b.second || a.second == b.second && a.first < b.first;
	});
	long long l = 0, mx = 0;
	for(int i =0; i<n; ++i) {
		if (i && a[i].second != a[i - 1].second)
			l = max(l, mx), mx = 0;
		if (l > a[i].first) {
			long long d = (l - a[i].first + 29) / 30;
			sum += d;
			a[i].first += d * 30;
		}
		mx = max(mx, a[i].first);
	}
	cout << sum;
}