#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	sort(a.begin(), a.end());
	long long ans = 0, cnt = 0;
	for(int i : a) {
		if (i - cnt > 0) {
			if (i - cnt - 1 > 0) {
				ans += i - cnt - 1;
			}
			cnt++;
		}
	}
	cout << ans;
}