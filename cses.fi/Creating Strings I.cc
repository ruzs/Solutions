#include <bits/stdc++.h>

using namespace std;

int fac(int x) { return x > 1 ? fac(x - 1) * x : 1; }
int main() {
	string s;
	cin >> s;
	int ab[26]{};
	for(char c : s) ab[c - 'a']++;
	int a = fac(s.size());
	for(int i =0; i<26; ++i) a /= fac(ab[i]);
	sort(s.begin(), s.end());
	cout << a << '\n';
	do {
		cout << s << '\n';
	} while(next_permutation(s.begin(), s.end()));
}