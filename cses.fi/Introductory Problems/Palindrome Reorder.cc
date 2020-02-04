#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int ab[26]{};
	for(char c : s) ab[c - 'A']++;
	int o =0, x =0;
	for(int i =0; i<26; ++i) if (ab[i] & 1) o++, x = i;
	if (o > 1) {
		cout << "NO SOLUTION";
	}
	else {
		for(int i =0; i<26; ++i) {
			if (i == x) continue;
			for(int j =0; j+j<ab[i]; ++j) cout << static_cast<char>('A' + i);
		}
		for(int j =0; j<ab[x]; ++j) cout << static_cast<char>('A' + x);
		for(int i =25; ~i; --i) {
			if (i == x) continue;
			for(int j =0; j+j<ab[i]; ++j) cout << static_cast<char>('A' + i);
		}
	}
}