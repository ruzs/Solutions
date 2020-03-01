#include <bits/stdc++.h>
using namespace std;

int n;
string s;
set<string> S;
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> s;
		S.insert(s);
		reverse(s.begin(), s.end());
		if (S.count(s)) {
			cout << s.size() << ' ' << s[s.size() / 2];
			return 0;
		}
	}
}
