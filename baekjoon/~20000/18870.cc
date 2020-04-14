#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> ans(n);
	map<int, vector<int>> mp;
	for(int i =0; i<n; ++i) {
		int b;
		cin >> b;
		mp[b].push_back(i);
	}
	int k =0;
	for(auto& i : mp) {
		for(int j : i.second) {
			ans[j] = k;
		}
		k++;
	}
	for(int i : ans) cout << i << ' ';
}