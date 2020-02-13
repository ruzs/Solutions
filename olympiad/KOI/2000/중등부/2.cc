#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1,-1,0,0};
const int dx[] = {0,0,1,-1};
int n, m, pre[101][101], cur[101][101];
void init(int y, int x) {
	cur[y][x] = 2;
	for(int w =0; w<4; ++w) {
		int ny = y + dy[w], nx = x + dx[w];
		if (ny < 0 || nx < 0 || ny == n || nx == m) continue;
		if (cur[ny][nx] == 0) init(ny, nx);
	}
}
int main() {
	cin >> n >> m;
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			cin >> cur[i][j];
		}
	}
	init(0, 0);
	memcpy(pre, cur, sizeof cur);
	int cnt = 0;
	while(1) {
		bool update = 0;
		for(int i =0; i<n; ++i) {
			for(int j =0; j<m; ++j) {
				if (pre[i][j] == 1) {
					int c = 0;
					for(int w =0; w<4; ++w) {
						if (pre[i + dy[w]][j + dx[w]] == 2) c++;
					}
					if (c >= 2) {
						update = 1;
						init(i, j);
					}
				}
			}
		}
		if (!update) break;
		cnt++;
		memcpy(pre, cur, sizeof cur);
	}
	cout << cnt;
}