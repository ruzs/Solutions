#include <bits/stdc++.h>
using namespace std;

string s;
int sol(string s) {
	int r = 1;
	for(char c : s) r *= c & 15;
	return r;
}
int main() {
	cin >> s;
	for(int i =1; i<s.size(); ++i) {
		if (sol(s.substr(0, i)) == sol(s.substr(i, s.size() - i))) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
