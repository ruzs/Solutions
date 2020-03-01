#include <bits/stdc++.h>

using namespace std;

int main() {
	const int enc[] = {21,0,22,1,2,3,4,5,23,6,7,8,9,24,10,11,12,13,14,25,15,16,17,18,19,20};
	int n, m, a[51]{};
	char s[16];
	cin >> n >> m;
	m -= 5;
	if (m < 0) return cout << 0, 0;
	for(int i =0; i<n; ++i) {
		cin >> s;
		for(int j =0; s[j]; ++j) {
			a[i] |= (1 << enc[s[j] - 'a']);
		}
		a[i] &= (1 << 21) - 1;
	}
	int ans = 0;
	for(int s =0; s<1<<21; ++s) {
		if (__builtin_popcount(s) == m) {
			int cnt = 0;
			for(int i =0; i<n; ++i) {
				if((s & a[i]) == a[i]) cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans;
}