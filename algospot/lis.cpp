#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
int t, n;
int lis(vi & v) {
	vi r = {-1000000};
	for(int i : v) {
		if (r.back() < i) r.push_back(i);
		else *lower_bound(r.begin(), r.end(), i) = i;
	}
	return r.size() - 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n;
		vi v(n);
		for(int &i : v) cin >> i;
		cout << lis(v) << '\n';
	}
}
