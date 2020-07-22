#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	multiset<int> ms;
	for(int i =1; i<k; ++i) ms.insert(0);
	vector<pair<int, int>> a(n);
	for(auto & i : a) cin >> i.first >> i.second;
	sort(a.begin(), a.end(), [](auto& a, auto& b){
		return a.second < b.second || a.second == b.second && a.first < b.first;
	});
	int l = 0, cnt = 0;
	for(auto & i : a) {
		if (i.first > l) {
			auto lb = ms.lower_bound(i.first);
			if (lb != ms.begin()) {
				ms.erase(prev(lb));
				ms.insert(i.second);
			} else {
				l = i.second;
				cnt++;
			}
		}
	}
	cout << cnt;
}