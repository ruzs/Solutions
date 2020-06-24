#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<long long> c = {1};
	for(int i = 1; i<=30; ++i) c.push_back(2 * (2 * i - 1) * c.back() / (i + 1));
	int n;
	while(cin >> n) {
		if (!n) break;
		cout << c[n] << '\n';
	}
}