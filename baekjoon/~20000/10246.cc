#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a(1000001, 0);
	int ps = 0;
	for(int i =1; i<=1000000; ++i) {
		ps += i + 1;
		if (ps > 1000000) break;
		for(int j =ps; j<=1000000; j += i) {
			a[j]++;
		}
	}
	int n;
	while(cin >> n) {
		if (!n) break;
		cout << a[n] << '\n';
	}
}