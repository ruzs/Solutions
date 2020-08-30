#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t = "";
	cin >> s;
	bool f = 0;
	stack<char> st;

	if (s.size() & 1) f = 1;
	for(int i =0; i+1<s.size(); i+=2) {
		if (s[i] != s[i + 1]) f = 1;
		else if (s[i] == '<') {
			if (st.size() && st.top() == '>') {
				st.pop();
				t += ']';
			} else {
				st.push('<');
				t += '[';
			}
		} else {
			if (st.size() && st.top() == '<') {
				st.pop();
				t += ']';
			} else {
				st.push('>');
				t += '[';
			}
		}
	}
	if (st.size()) f = 1;
	if (f) cout << "Keine Loesung";
	else cout << t;
}