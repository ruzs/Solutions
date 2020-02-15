#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, a[300005];
	cin >> n >> k;
	for(int i =0; i<n; ++i) cin >> a[i];
	priority_queue<pair<int, int>> pq;
	for(int i =1; i<n; ++i) pq.push({a[i] - a[i - 1], i});
	long long ans =0;
	vector<int> s = {0};
	while(--k && pq.size()) s.push_back(pq.top().second), pq.pop();
	sort(s.begin(), s.end());
	for(int i =1; i<s.size(); ++i) {
		ans += a[s[i] - 1] - a[s[i - 1]];
	}
	ans += a[n - 1] - a[s.back()];
	cout << ans;
}