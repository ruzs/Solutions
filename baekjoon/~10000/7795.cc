#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(int & i : a) cin >> i;
		for(int & i : b) cin >> i;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int ans = 0;
		for(int i =n-1, j =m-1; i>=0; --i) {
			while (j >= 0 && a[i] <= b[j]) j--;
			ans += j + 1;
		}
		cout << ans << '\n';
	}
}