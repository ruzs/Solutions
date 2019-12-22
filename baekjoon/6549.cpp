#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
long long a[N], ans;
void max_area(int l, int r) {
	if (l > r) return;
	if (l == r) {
		ans = max(ans, a[l]);
		return;
	}
	int m = (l + r) / 2, i = m, j = m + 1;
	long long w = 2, mh = min(a[i], a[j]);

	ans = max(ans, w * mh);
	max_area(l, i);
	max_area(j, r);

	while(l < i || j < r) {
		if (l < i && j < r) {
			if (a[i - 1] < a[j + 1]) j++;
			else i--;
		}
		else if (l < i) i--;
		else j++;
		w++;
		mh = min({mh, a[i], a[j]});
		ans = max(ans, w * mh);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while(n){
		for(int i =0; i<n; ++i) cin >> a[i];
		ans = 0;
		max_area(0, n - 1);
		cout << ans << '\n';
		cin >> n;
	}
}
