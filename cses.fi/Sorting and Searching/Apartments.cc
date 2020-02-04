#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, x;
	cin >> n >> m >> k;
	priority_queue<int> a,b;
	while(n--) cin >> x, a.push(x);
	while(m--) cin >> x, b.push(x);
	int ans =0;
	while(a.size() && b.size()) {
		if (abs(a.top() - b.top()) <= k) {
			a.pop();
			b.pop();
			ans++;
		}
		else if (a.top() > b.top()) a.pop();
		else b.pop();
	}
	cout << ans;
}