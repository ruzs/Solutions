#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int main() {
	cin >> n;
	while(n--) {
		cin.ignore();
		getline(cin, s);
		s.replace(s.begin(), s.begin() + s.find_first_of(' '), "god");
		for(char c : s) if (c != ' ') cout << c;
		cout << '\n';
	}
}
