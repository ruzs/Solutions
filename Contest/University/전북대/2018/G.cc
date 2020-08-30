#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	stack<int> st;
	for(char c : s) {
		if (c == '+') {
			int x = st.top();
			st.pop();
			st.top() += x;
		} else if (c == '-') {
			int x = st.top();
			st.pop();
			st.top() -= x;
		} else if (c == '*') {
			int x = st.top();
			st.pop();
			st.top() *= x;
		} else if (c == '/') {
			int x = st.top();
			st.pop();
			st.top() /= x;
		} else {
			st.push(c & 15);
		}
	}
	cout << st.top();
}