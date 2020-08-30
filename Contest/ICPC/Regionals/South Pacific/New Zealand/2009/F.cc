#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string line;
	while (getline(cin, line)) {
		if (line == "#") break;
		bool f = 0;
		stack<char> st;
		for(char c : line) {
			if (c == '(') st.push(')');
			else if (c == '[') st.push(']');
			else if (c == '{') st.push('}');
			else if (c == ')' || c == ']' || c == '}') {
				if (st.empty() || st.top() != c) f = 1;
				else st.pop();
			}
		}
		if (st.size()) f = 1;
		if (f) cout << "Illegal\n";
		else cout << "Legal\n";
	}
}