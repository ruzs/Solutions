#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		a[x - 1] = i;
	}
	for(int i =0; i<n; ++i) {
		int x; cin >> x;
		b[i] = a[x - 1];
	}
	vector<int> d = {(int)-1e9};
	for(int i : b) {
		if (d.back() < i) d.push_back(i);
		else *lower_bound(d.begin(), d.end(), i) = i;
	}
	cout << d.size() - 1;
}