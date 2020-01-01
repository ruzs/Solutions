#include <bits/stdc++.h>
using namespace std;

char s[2001], t[2001];
int rearrange(int i) {
	int l = i, m, r;
	for(int c =0; c<4; ++c) {
		if (s[i] == 'x') i = rearrange(i + 1);
		else i++;
		if (c == 1) m = i;
	}
	r = i;
	for(int j =l; j<m; ++j) t[j] = s[j];
	for(int j =m; j<r; ++j) s[j - m + l] = s[j];
	for(int j =l; j<m; ++j) s[j + r - m] = t[j];
	return i;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while(t--){
		cin >> s;
		if (s[0] == 'x') rearrange(1);
		cout << s << '\n';
	}
}
