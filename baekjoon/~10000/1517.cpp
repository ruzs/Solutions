#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

int n, a[N], b[N];
long long ans;
void merge_sort(int s, int e) {
	if (s + 1 >= e) return;
	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m, e);
	memcpy(b + s, a + s, (e - s) << 2);
	for(int i = s, li = s, ri = m; li < m || ri < e;) {
		if (li >= m) a[i++] = b[ri++];
		else if (ri >= e || b[li] <= b[ri]) a[i++] = b[li++];
		else a[i++] = b[ri++], ans += m - li;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	merge_sort(0, n);
	cout << ans;
}
