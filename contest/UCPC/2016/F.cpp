#include <bits/stdc++.h>
using namespace std;

int n, k, p, np;
priority_queue<int> pq;
long long ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> p;
	for(int i =1; i<n; ++i) {
		cin >> np;
		pq.push(np - p);
		ans += np - p;
		p = np;
	}
	while(--k) {
		ans -= pq.top(); pq.pop();
	}
	cout << ans;
}
