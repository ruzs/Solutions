#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a[200005], ans = 0;
	set<int> s;
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	for(int l =0, r =0; r<n; ++r) {
		if (s.count(a[r])) {
			ans = max(ans, (int)s.size());
			while(a[l] != a[r]) s.erase(a[l++]);
			s.erase(a[l++]);
		}
		s.insert(a[r]);
	}
	cout << max(ans, (int)s.size());
}