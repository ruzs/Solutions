#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int cnt = 0;
	char pre = 'A';
	for(char c : s) {
		cnt += min(abs(c - pre), 26 - abs(pre - c));
		pre = c;
	}
	cout << cnt;
}