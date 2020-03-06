#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(auto & i : a) cin >> i.first >> i.second;
	sort(a.begin(), a.end());
	priority_queue<int> pq;
	for(auto & i : a) {
		pq.push(-i.second);
		while(pq.size() > i.first) pq.pop();
	}
	int ans = 0;
	while(pq.size()) ans -= pq.top(), pq.pop();
	cout << ans;
}