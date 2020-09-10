#include <bits/stdc++.h>

using namespace std;

int dice[7];
int n, m, a, b, c, d;
int D[2][100][7][7];
queue<tuple<int, int, int, int>> q;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, test_case;
	cin >> T;
	for(test_case = 1; test_case <= T; test_case++) {
		for(int i =1; i<=6; ++i) {
			int x; cin >> x;
			dice[x] = i;
		}
		int left[7][7] = { {},
			{0, 0, 4, 0, 5, 6, 2},
			{0, 6, 0, 4, 1, 0, 3},
			{0, 0, 6, 0, 2, 4, 5},
			{0, 2, 3, 5, 0, 1, 0},
			{0, 4, 0, 6, 3, 0, 1},
			{0, 5, 1, 2, 0, 3, 0}};
		int up[7][7] = { {},
			{0, 0, 5, 0, 6, 2, 4},
			{0, 3, 0, 1, 6, 0, 4},
			{0, 0, 5, 0, 6, 2, 4},
			{0, 3, 5, 1, 0, 2, 0},
			{0, 3, 0, 1, 6, 0, 4},
			{0, 3, 5, 1, 0, 2, 0}};

		cin >> n >> m >> a >> b >> c >> d;

		memset(D, -1, sizeof D);
		while (q.size()) q.pop();

		D[0][0][dice[a]][dice[b]] = 0;
		q.push({0, 0, dice[a], dice[b]});

		while (q.size()) {
			auto [y, x, f, t] = q.front(); q.pop();
			if (y == n - 1 && x == m - 1 && f == dice[c] && t == dice[d]) break;
			if (x + 1 < m) {
				int nt = left[f][t];
				if (D[y][x + 1][f][nt] == -1) {
					D[y][x + 1][f][nt] = D[y][x][f][t] + 1;
					q.push({y, x + 1, f, nt});
				}
			}
			if (x > 0) {
				int nt = left[f][left[f][left[f][t]]];
				if (D[y][x - 1][f][nt] == -1) {
					D[y][x - 1][f][nt] = D[y][x][f][t] + 1;
					q.push({y, x - 1, f, nt});
				}
			}
			if (y > 0) {
				int nf = up[f][t];
				if (D[y - 1][x][nf][f] == -1) {
					D[y - 1][x][nf][f] = D[y][x][f][t] + 1;
					q.push({y - 1, x, nf, f});
				}
			}
			if (y + 1 < n) {
				int nf = f, nt = t, tmp;
				for(int i =0; i<3; ++i) {
					tmp = nt;
					nt = nf;
					nf = up[nf][tmp];
				}
				if (D[y + 1][x][nf][nt] == -1) {
					D[y + 1][x][nf][nt] = D[y][x][f][t] + 1;
					q.push({y + 1, x, nf, nt});
				}
			}
		}
		cout << "Case #" << test_case << endl;
		cout << D[n - 1][m - 1][dice[c]][dice[d]] << endl;
	}
	return 0;
}