#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	char r =0;
	int ans =0, cnt =0;
	for(char c : s) {
		if (c == r) cnt++;
		else ans = max(ans, cnt), cnt = 1, r = c;
	}
	cout << max(ans, cnt);
}