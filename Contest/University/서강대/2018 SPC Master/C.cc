#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> q(5000001);
	for(long long i =2, j; i<=5000000; ++i) {
		if (q[i]) continue;
		for(j = i * i; j<=5000000; j+=i)
			if (!q[j]) q[j] = i;
	}
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		while(q[x]) {
			cout << q[x] << ' ';
			x /= q[x];
		}
		cout << x << '\n';
	}
}