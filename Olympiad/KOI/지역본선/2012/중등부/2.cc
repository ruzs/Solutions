#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d, k, b;
	cin >> n >> d >> k >> b;
	vector<int> a(n), c(d + 1);
	for(int & i : a) cin >> i;
	a.insert(a.end(), a.begin(), a.end());
	int ans = 0, cnt = 0;
	for(int i =0, j =0; j<2*n; ++j) {
		if (!c[a[j]]++) cnt++;
		if (j - i + 1 == k) {
			ans = max(ans, cnt + !c[b]);
			if (!--c[a[i++]]) cnt--;
		}
	}
	cout << ans;
}