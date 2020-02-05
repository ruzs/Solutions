#include <bits/stdc++.h>

using namespace std;

bool solve() {
	string s, st;
	cin >> s;
	for(char c : s) {
		if (c == '[' || c == '(' || c == '{') st += c;
		else if (st.empty()) return 1;
		else if (c == ']' && st.back() != '[') return 1;
		else if (c == '}' && st.back() != '{') return 1;
		else if (c == ')' && st.back() != '(') return 1;
		else st.pop_back();
	}
	return st.size();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) if (solve()) cout << "NO\n"; else cout << "YES\n";
}