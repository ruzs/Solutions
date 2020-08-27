#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	int ans, mn = 1e9;
	for(int i =0, j =n-1; i<j;) {
		if (mn > abs(a[i] + a[j])) {
			mn = abs(a[i] + a[j]);
			ans = a[i] + a[j];
		}
		if (a[i] + a[j] < 0) i++;
		else j--;
	}
	cout << ans;
}