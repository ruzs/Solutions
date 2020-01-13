#include <bits/stdc++.h>
using namespace std;

int n, m;
long long ans = 1;
int main() {
	cin >> n >> m;
	for(int i =0; i<m; ++i) {
		ans *= n / m + (i < n%m);
	}
	cout << ans;
}
