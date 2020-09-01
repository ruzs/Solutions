#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const long long mod = 12345678910ll;
	int n;
	cin >> n;
	stack<long long> st;
	while (n--) {
		int x; cin >> x;
		if (x) {
			long long sum = 0;
			bool f = 0;
			while (st.size() && st.top() >= 0) {
				sum = (sum + st.top()) % mod;
				st.pop();
				f = 1;
			}
			st.pop();
			if (f) st.push(sum * 2 % mod);
			else st.push(1);
		} else {
			st.push(-1);
		}
	}
	long long ans = 0;
	while (st.size()) {
		ans = (ans + st.top()) % mod;
		st.pop();
	}
	cout << ans;
}