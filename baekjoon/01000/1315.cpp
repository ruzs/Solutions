#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

struct Quest {
	int s, i, p;
} q[101];
int n, S[101], I[101], D[101][101], P[101][101], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =1; i<=n; ++i) {
		cin >> q[i].s >> q[i].i >> q[i].p;
		S[i] = q[i].s;
		I[i] = q[i].i;
	}
    S[0] = I[0] = 1;
	sort(S + 1, S + n + 1);
	sort(I + 1, I + n + 1);
    D[0][0] = 1;
	for(int s =0; s<=n; ++s) {
		for(int i =0; i<=n; ++i) {
			P[s][i] = 2 - S[s] - I[i];
			int cnt = 0;
			for(int j =1; j<=n; ++j) {
				if (q[j].s <= S[s] || q[j].i <= I[i]) {
					P[s][i] += q[j].p;
					cnt++;
				}
			}
			if (s && D[s - 1][i] && P[s - 1][i] >= S[s] - S[s - 1]) D[s][i] = 1;
			if (i && D[s][i - 1] && P[s][i - 1] >= I[i] - I[i - 1]) D[s][i] = 1;
			if (D[s][i]) ans = max(ans, cnt);
		}
	}
	cout << ans;
}
