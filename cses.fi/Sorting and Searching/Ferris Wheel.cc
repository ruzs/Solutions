#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	deque<int> dq(n);
	for(int & i : dq) cin >> i;
	sort(dq.begin(), dq.end());
	int ans =0, s = x;
	while(dq.size()) {
		if (dq.back() <= s) s -= dq.back(), dq.pop_back();
		if (dq.size() && dq.back() <= s) s -= dq.back(), dq.pop_back();
		else if (dq.size() && dq.front() <= s) s -= dq.front(), dq.pop_front();
		ans++;
		s = x;
	}
	cout << ans;
}