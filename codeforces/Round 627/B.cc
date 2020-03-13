#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int  t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n + 1, -1);
		bool ok = 0;
		for(int i =0; i<n; ++i) {
			int x;
			cin >> x;
			if (~a[x] && a[x] + 1 < i) ok = 1;
			a[x] = i;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
}