#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a;
	cin >> n;
	priority_queue<int> q;
	long long ans = 0;
	for(int i =0; i<n; ++i) {
		cin >> a;
		q.push(a -= i);
		if (q.top() >= a) {
			ans += q.top() - a;
			q.pop();
			q.push(a);
		}
	}
	cout << ans;
}