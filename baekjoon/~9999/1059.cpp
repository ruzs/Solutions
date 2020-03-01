#include <bits/stdc++.h>
using namespace std;

int n, a[51], m;
int main() {
	cin >> n;
	for(int i =1; i<=n; ++i) cin >> a[i];
	cin >> m;
	sort(a + 1, a + n + 1);
	auto lb = lower_bound(a + 1, a + n + 1, m) - a;
	if (a[lb] == m) cout << 0;
	else {
		cout << (a[lb] - m) * (m - a[lb - 1]) - 1;
	}
}
