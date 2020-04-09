#include <bits/stdc++.h>

using namespace std;

int n, k, a[1000005];
deque<int> dq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for(int i =0; i<n; ++i)
		cin >> a[i];
	sort(a, a + n);
	for(int j =1; j<n - k - 1; ++j) {
		int d = a[j] - a[j - 1];
		while(dq.size() && dq.back() > d)
			dq.pop_back();
		dq.push_back(d);
	}
	int ans = 1e9;
	for(int i =0, j =n - k - 1; j<n; ++j, ++i) {
		int d = a[j] - a[j - 1];
		while(dq.size() && dq.back() > d)
			dq.pop_back();
		dq.push_back(d);
		ans = min(ans, a[j] - a[i] + dq.front());
		if (dq.front() == a[i + 1] - a[i])
			dq.pop_front();
	}
	cout << ans;
}