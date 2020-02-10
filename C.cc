#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a[100005], bc[31];
	cin >> n;
	vector<int> ans;
	for(int i =0; i<n; ++i) {
		cin >> a[i];
		for(int j =0; j<31; ++j)
			if (a[i] & (1 << j)) bc[j]++;
	}
	sort(a, a + n, [&](int a, int b) {
		for(int j =30; ~j; --j) {
			if ((a & (1 << j)) && bc[j] == 1) return 1;
			if ((b & (1 << j)) && bc[j] == 1) return 0;
		}
		return 0;
	});
	for(int i =0; i<n; ++i) cout << a[i] << ' ';
}