#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	while (m--) {
		int i, j;
		cin >> i >> j;
		a[i]++;
		a[j + 1]--;
	}
	partial_sum(a.begin(), a.end(), a.begin());
	nth_element(a.begin(), a.begin() + n / 2, a.end() - 1);
	cout << a[n / 2];
}