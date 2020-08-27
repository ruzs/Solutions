#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	sort(a.begin(), a.end());
	int ans = 4;
	for(int i =0, j =0; j<n; ++j) {
		while (a[i] + 4 < a[j]) i++;
		ans = min(ans, 5 - (j - i + 1));
	}
	cout << ans;
}