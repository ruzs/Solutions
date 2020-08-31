#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (cin >> s) {
		s = '(' + s + ')';
		stack<char> st, tmp;
		stack<bitset<26>> a, atmp;
		bitset<26> x;
		for(char c : s) {
			if (c == '{') {
				x.reset();
			} else if (c == '}') {
				a.push(x);
			} else if (c == '(') {
				st.push(')');
			} else if (c == ')') {
				atmp.push(a.top());
				a.pop();
				while (st.size() && st.top() != c) {
					if (st.top() == '*') {
						atmp.top() &= a.top();
					} else {
						atmp.push(a.top());
						tmp.push(st.top());
					}
					st.pop();
					a.pop();
				}
				st.pop();
				a.push(atmp.top());
				atmp.pop();
				while (tmp.size()) {
					if (tmp.top() == '+') {
						a.top() |= atmp.top();
					} else {
						a.top() &= ~atmp.top();
					}
					atmp.pop();
					tmp.pop();
				}
			} else if (isalpha(c)) {
				x[c - 'A'] = 1;
			} else {
				st.push(c);
			}
		}
		cout << '{';
		for(int i =0; i<26; ++i)
			if (a.top()[i])
				cout << static_cast<char>(i + 'A');
		cout << "}\n";
	}
}