#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i =0; i<n; ++i) {
		cin >> a[i];
	}
	cout << a[0] << ' ';
	long long mx = a[0];
	for(int i =1; i<n; ++i) {
		cout << (a[i] += (mx = max(mx, a[i - 1]))) << ' ';
	}
}