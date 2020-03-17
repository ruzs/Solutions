#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(100001);
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		a[x]++;
	}
	int ans = -1;
	for(int i =0; i<=100000; ++i) {
		if (a[i] == i) {
			ans = i;
		}
	}
	cout << ans;
}