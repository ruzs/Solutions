#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i =0, j =n-1; i<j; ++i) {
		while (i < j && a[i] + a[j] > m) j--;
		ans += j - i;
	}
	cout << ans;
}