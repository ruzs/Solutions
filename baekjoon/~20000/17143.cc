#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[2][101][101];
struct shark {
	int r, c, s, d, z, sinu = 0;
} s[10001];

int main() {

	cin >> n >> m >> k;
	for(int i =1; i<=k; ++i) {
		cin >> s[i].r >> s[i].c >> s[i].s >> s[i].d >> s[i].z;
		a[1][s[i].r][s[i].c] = i;
		s[i].d--;
	}

	int ans = 0;
	for(int i =1, x =1; i<=m; ++i, x^=1) {
		for(int j =1; j<=n; ++j) if (a[x][j][i]) {
			s[a[x][j][i]].sinu = 1;
			ans += s[a[x][j][i]].z;
			a[x][j][i] = 0;
			break;
		}
		for(int j =1; j<=k; ++j) {
			if (s[j].sinu) continue;
			int& nr = s[j].r;
			int& nc = s[j].c;
			a[x][nr][nc] = 0;
			if (s[j].d > 1) {
				if (s[j].d == 2) nc += s[j].s;
				else nc -= s[j].s;
				while(nc > m || nc < 1) {
					if (nc > m) nc = 2*m - nc, s[j].d = 3;
					if (nc < 1) nc = 2 - nc, s[j].d = 2;
				}
			}
			else {
				if (s[j].d == 0) nr -= s[j].s;
				else nr += s[j].s;
				while(nr > n || nr < 1) {
					if (nr > n) nr = 2*n - nr, s[j].d = 0;
					if (nr < 1) nr = 2 - nr, s[j].d = 1;
				}
			}
			if (s[a[x^1][nr][nc]].z < s[j].z)
				s[a[x^1][nr][nc]].sinu = 1, a[x^1][nr][nc] = j;
			else s[j].sinu = 1;
		}
		memset(a[x], 0, sizeof a[x]);
	}
	cout << ans;
}