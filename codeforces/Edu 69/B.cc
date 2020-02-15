#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a[200005], p{};
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	for(int i =1; i<n; ++i) {
		if (a[i] < a[i - 1]) p = 1;
		else if (p) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}