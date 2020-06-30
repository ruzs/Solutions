#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> c(n + 1);
	int ans = 0, cnt = 0;
	for(int i =0; i<2*n; ++i) {
		int x; cin >> x;
		if (c[x]) cnt--, c[x]--;
		else cnt++, c[x]++;
		ans = max(ans, cnt);
	}
	cout << ans;
}