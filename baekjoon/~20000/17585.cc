#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> ab(n);
	for(int & i : ab) {
		char c; cin >> c;
		if (c == 'T') i = 1;
	}
	char c;
	stack<int> st;
	while (cin >> c) {
		if (c == '*') {
			int x = st.top();
			st.pop();
			st.top() &= x;
		} else if (c == '+') {
			int x = st.top();
			st.pop();
			st.top() |= x;
		} else if (c == '-') {
			st.top() = !st.top();
		} else {
			st.push(ab[c - 'A']);
		}
	}
	cout << (st.top() ? 'T' : 'F');
}