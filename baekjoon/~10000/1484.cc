#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<long long> sqr(100000);
	for(long long i =0; i<100000; ++i) sqr[i] = (i + 1) * (i + 1);
	vector<int> ans;
	for(int i =0; i<100000; ++i) {
		if (binary_search(sqr.begin(), sqr.begin() + i, sqr[i] - n)) ans.push_back(i + 1);
	}
	if (ans.empty()) cout << -1;
	else for(int i : ans) cout << i << '\n';
}