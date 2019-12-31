#include <bits/stdc++.h>

using namespace std;

const int dz[] = {1,0,0,0,0,-1}, dy[] = {0,1,0,-1,0,0}, dx[] = {0,0,1,0,-1,0};
int a[5][5][5], b[5] = {0,1,2,3,4}, bi[5], v[5][5][5], t[5];
void rotate(int x) {
	for(int i =0; i<5; ++i) t[i] = a[x][0][i];
	for(int i =0; i<5; ++i) a[x][0][i] = a[x][i][4];
	for(int i =0; i<5; ++i) a[x][i][4] = a[x][4][4-i];
	for(int i =0; i<5; ++i) a[x][4][4-i] = a[x][4-i][0];
	for(int i =0; i<5; ++i) a[x][4-i][0] = t[i];
	for(int i =1; i<4; ++i) t[i] = a[x][1][i];
	for(int i =1; i<4; ++i) a[x][1][i] = a[x][i][3];
	for(int i =1; i<4; ++i) a[x][i][3] = a[x][3][4-i];
	for(int i =1; i<4; ++i) a[x][3][4-i] = a[x][4-i][1];
	for(int i =1; i<4; ++i) a[x][4-i][1] = t[i];
}
bool valid(int z, int y, int x) {
	return z >= 0 && z < 5 && y >= 0 && y < 5 && x >= 0 && x < 5;
}
int nextz(int z, int x) {
	if (x) {
		if (x > 0 && bi[z] == 4) return -1;
		if (x < 0 && bi[z] == 0) return -1;
		return b[bi[z] + x];
	}
	return z;
}
int bfs() {
	if (!a[b[0]][0][0] || !a[b[4]][4][4]) return 1e9;
	memset(v, 0, sizeof v);
	queue<tuple<int, int, int>> q;
	q.push({b[0], 0, 0});
	v[b[0]][0][0] = 1;

	while(q.size()) {
		auto [z, y, x] = q.front(); q.pop();
		if (z == b[4] && y == 4 && x == 4) return v[z][y][x] - 1;
		for(int w =0; w<6; ++w) {
			int nz = nextz(z, dz[w]), ny = y + dy[w], nx = x + dx[w];
			if (valid(nz, ny, nx) && a[nz][ny][nx] && !v[nz][ny][nx]) {
				v[nz][ny][nx] = v[z][y][x] + 1;
				q.push({ nz, ny, nx });
			}
		}
	}
	return 1e9;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int h =0; h<5; ++h) {
		for(int i =0; i<5; ++i) {
			for(int j =0; j<5; ++j) {
				cin >> a[h][i][j];
			}
		}
	}

	int ans = 1e9;
	do {
		for(int i =0; i<5; ++i) bi[b[i]] = i;
		for(int a =0; a<4; ++a) {
			for(int b =0; b<4; ++b) {
				for(int c =0; c<4; ++c) {
					for(int d =0; d<4; ++d) {
						for(int e =0; e<4; ++e) {
							ans = min(ans, bfs());
							rotate(4);
						} rotate(3);
					} rotate(2);
				} rotate(1);
			} rotate(0);
		}
	} while(next_permutation(b, b + 5));
	cout << (ans < 1e9 ? ans : -1);
}
