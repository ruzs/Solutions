#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
	double ans = 0;
	cin >> n;
	for(int i =1; i<=n; ++i) ans += 1.0 / i;
	cout << setprecision(20) << ans;
}