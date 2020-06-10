#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a[2000005]{};
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		a[x]++;
	}
	long long ans = 0, cnt;
	for(int i =1; i<=2000000; ++i) {
		cnt = 0;
		for(int j =i; j<=2000000; j+=i){
			if (a[j]) cnt += (long long)i * a[j];
		}
		if (cnt > i) ans = max(ans, cnt);
	}
	cout << ans;
}