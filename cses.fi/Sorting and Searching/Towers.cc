#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a;
	vector<int> v = {(int)-1e9};
	cin >> n;
	while(n--) {
		cin >> a;
		if (v.back() <= a) v.push_back(a);
		else *lower_bound(v.begin(), v.end(), a) = a;
	}
	cout << v.size() - 1;
}