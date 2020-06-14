#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, n, v[400005]{};
	cin >> w >> n;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	for(int i =0; i<n; ++i) {
		for(int j =i + 1; j<n; ++j) {
			int s = w - a[i] - a[j];
			if (s < 0 || s > 400000) continue;
			if (v[s] && v[s] < i) {
				cout << "YES";
				return 0;
			}
			v[a[i] + a[j]] = j;
		}
	}
	cout << "NO";
}