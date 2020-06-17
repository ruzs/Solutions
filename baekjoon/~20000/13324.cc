#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a;
	cin >> n;
	priority_queue<int> q;
	vector<int> ans(n);
	for(int i =0; i<n; ++i) {
		cin >> a;
		q.push(a -= i);
		q.push(a);
		q.pop();
		ans[i] = q.top();
	}
	for(int i =n-2; i>=0; --i)
		if (ans[i] > ans[i + 1]) ans[i] = ans[i + 1];
	for(int i =0; i<n; ++i) cout << ans[i] + i << '\n';
}