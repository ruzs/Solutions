#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		stack<char> st;
		bool f = 0;
		for(char c : s) {
			if (c == '>') st.push('<');
			else if (st.empty() || st.top() != c) f = 1;
			else st.pop();
		}
		if (st.size() || f) cout << "illegal\n";
		else cout << "legal\n";
	}
}