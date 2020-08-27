#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<long long> p = {0}, pp = {0};
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		p.push_back(p.back() + x);
		pp.push_back(pp.back() + x * x);
	}
	long long ans = 0;
	for(int i =1; i<=n; ++i) {
		ans = max(ans, pp[i] * (p[n] - p[i]));
	}
	cout << ans;
}