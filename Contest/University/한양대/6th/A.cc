#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int, int>> st;
	int ans = 0;
	for(int i =0; i<n; ++i) {
		int a, b, c;
		cin >> a;
		if (a) {
			cin >> b >> c;
			st.push({b, c});
		}
		if (st.size() && !--st.top().second) {
			ans += st.top().first;
			st.pop();
		}
	}
	cout << ans;
}