#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, o, msk[10001]{};
	char c, s[1001];
	
	cin >> n >> m;
	for(int i =0; i<n; ++i) {
		cin >> s;
		for(int j =0; s[j]; ++j) msk[i] |= 1 << s[j] - 'a';
	}
	int state = 0;
	while(m--) {
		cin >> o >> c;
		state ^= 1 << c - 'a';
		int cnt = 0;
		for(int i =0; i<n; ++i) 
			if (!(state & msk[i])) cnt++;
		cout << cnt << '\n';
	}
}