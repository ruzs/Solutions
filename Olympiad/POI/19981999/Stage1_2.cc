#include <bits/stdc++.h>

using namespace std;

int main() {
	int k, n, a;
	set<int> d[9];
	cin >> k >> n;
	for(int i =1, j =1; i<=11111111; i=i*10+1,j++) d[j].insert(k * i);
	for(int i =2; i<=8; ++i) {
		for(int j =1; j<=i/2; ++j) {
			for(int x : d[j]) {
				for(int y : d[i - j]) {
					d[i].insert(x - y);
					d[i].insert(y - x);
					d[i].insert(x + y);
					d[i].insert(x * y);
					if (y) d[i].insert(x / y);
					if (x) d[i].insert(y / x);
				}
			}
		}
	}
	while(n--) {
		cin >> a;
		int ans = 0;
		for(int i =1; i<=8; ++i) if (d[i].count(a)) {
			ans = i;
			break;
		}
		if (ans) cout << ans << '\n';
		else cout << "NO\n";
	}
}