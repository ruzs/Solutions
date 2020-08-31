#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	auto convert = [](string s) {
		int r = 0;
		for(char c : s) {
			if (c == '=') r += 10;
			else if (c == '-') r += 5;
			else if (c == ':') r += 2;
			else if (c == '.') r += 1;
		}
		return r;
	};
	stack<int> st;
	int n;
	cin >> n;
	string s;
	cin >> s;
	st.push(convert(s));
	while (n--) {
		char op;
		cin >> op >> s;
		if (op == '*') st.top() *= convert(s);
		else st.push(convert(s));
	}
	int r = 0;
	while (st.size()) {
		r += st.top();
		st.pop();
	}
	cout << r;
}