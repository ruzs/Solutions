#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const int mod = 1e9 + 7;
	int n;
	cin >> n;
	stack<int> st;
	int cnt = 0;
	while (n--) {
		string s;
		cin >> s;
		if (s == "(") {
			st.push(-1);
			cnt++;
		} else if (s == ")") {
			int sum = cnt & 1;
			while (st.size() && st.top() >= 0) {
				if (cnt & 1) {
					sum = 1ll * sum * st.top() % mod;
				} else {
					sum = (sum + st.top()) % mod;
				}
				st.pop();
			}
			st.pop();
			st.push(sum);
			cnt--;
		} else {
			st.push(stoi(s));
		}
	}
	int ans = 0;
	while (st.size()) {
		ans = (ans + st.top()) % mod;
		st.pop();
	}
	cout << ans;
}