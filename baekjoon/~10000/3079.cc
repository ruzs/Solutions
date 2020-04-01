#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	long long ans = 1e18, j = 1e18;
	while(j /= 2) {
		while([=](long long x){
			long long cnt = 0;
			for(auto & i : a) {
				cnt += x / i;
				if (cnt >= m) return 1;
			}
			return 0;
		}(ans - j)) ans -= j;
	}
	cout << ans;
}