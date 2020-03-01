#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	pair<int, int> a[200001];
	for(int i =0; i<n; ++i) cin >> a[i].first;
	for(int i =0; i<n; ++i) cin >> a[i].second;

	sort(a, a + n, [](auto a, auto b){ return a.second < b.second; });

	priority_queue<int> pq;
	long long s = 0;
	pq.push(a[0].first);
	for(int i =0; i<n; i+=2) {
		s += pq.top(); pq.pop();
		pq.push(a[i + 1].first);
		pq.push(a[i + 2].first);
	}
	cout << s;
}