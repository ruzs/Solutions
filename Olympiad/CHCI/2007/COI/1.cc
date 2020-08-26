#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	stack<pair<int, int>> st;
	long long ans = 0;
	while (n--) {
		int x;
		cin >> x;
		while (st.size() && st.top().first < x) {
			ans += st.top().second;
			st.pop();
		}
		if (st.size()) {
			if (st.top().first == x) {
				ans += st.top().second;
				auto tmp = st.top();
				st.pop();
				if (st.size()) ans++;
				st.push(tmp);
				st.top().second++;
			} else {
				ans++;
				st.push({x, 1});
			}
		} else {
			st.push({x, 1});
		}
	}
	cout << ans;
}