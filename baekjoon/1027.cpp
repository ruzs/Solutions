#include <bits/stdc++.h>
using namespace std;

int n, h[51], ans;
bool valid(int s, int e, int m) {
	double l = 1.0 * (h[e] - h[s]) / (e - s);
	return h[m] < l * (m - s) + h[s];
}
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) cin >> h[i];
	for(int i =0; i<n; ++i) {
		int cnt = 0;
		for(int j =0; j<n; ++j) {
			if (i == j) continue;
			int f =1, s =min(i, j), e =max(i, j);
			for(int k =s+1; k<e; ++k) {
				if (!valid(s, e, k)) {
					f =0;
					break;
				}
			}
			cnt += f;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}
