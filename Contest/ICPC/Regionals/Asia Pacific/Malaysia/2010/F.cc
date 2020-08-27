#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin >> tt;
	for(int t =1; t<=tt; ++t) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for(int & i : a) cin >> i;
		int ans = 0;
		for(int i =0, j =n-1; i<j; ++i) {
			while (a[i] + a[j] > x) j--;
			if (a[i] + a[j] == x) ans++;
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
}