#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0; i<n; ++i) cin >> a[i];
		if (any_of(a.begin(), a.end(),[&](int x){return (x & 1) != (a[0] & 1); })) cout << "NO\n";
		else cout << "YES\n";
	}
}