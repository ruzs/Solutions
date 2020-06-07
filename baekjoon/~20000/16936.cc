#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> a(n);
	for(auto & i : a) cin >> i;
	sort(a.begin(), a.end(), [](auto a, auto b) {
		int a3 = 0, b3 = 0;
		while(a % 3 == 0) a3++, a /= 3;
		while(b % 3 == 0) b3++, b /= 3;
		if (a3 != b3) return a3 > b3;
		int a2 = 0, b2 = 0;
		while(a % 2 == 0) a2++, a /= 2;
		while(b % 2 == 0) b2++, b /= 2;
		return a2 < b2;
	});
	for(auto i : a) cout << i << ' ';
}