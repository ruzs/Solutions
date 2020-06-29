#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int n;
	cin >> s >> n;
	while(n--) {
		string a;
		cin >> a;
		for(int i =0; i<26; ++i) {
			string b = a;
			for(char & c : b) c = c + i > 'z' ? c + i - 26 : c + i;
			if (s.find(b) < s.size()) {
				for(char d : s)
					cout << static_cast<char>(d - i < 'a' ? d - i + 26 : d - i);
				return 0;
			}
		}
	}
}