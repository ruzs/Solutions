#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> s[11];
	s[1] = {"*"};
	int Y = 3, X = 5;
	for(int i =2; i<=n; ++i) {
		s[i].resize(Y);
		if (i & 1) {
			for(int y =0; y<Y; ++y) {
				for(int x =1; x<Y-y; ++x) s[i][y] += ' ';
				if (!y) {
					s[i][y] += '*';
				} else if (y < Y / 2) {
					s[i][y] += '*';
					for(int x = 0; x<y*2-1; ++x) s[i][y] += ' ';
					s[i][y] += '*';
				} else if (y < Y - 1) {
					s[i][y] += '*';
					for(int x = 0; x<(y-Y/2); ++x) s[i][y] += ' ';
					s[i][y] += s[i - 1][y - Y/2];
					for(int x = 0; x<(y-Y/2)*2; ++x) s[i][y] += ' ';
					s[i][y] += '*';
				} else {
					for(int x = 0; x<X; ++x) s[i][y] += '*';
				}
			}
		} else {
			for(int y =0; y<Y; ++y) {
				for(int x =0; x<y; ++x) s[i][y] += ' ';
				if (!y) {
					for(int x= 0; x<X; ++x) s[i][y] += '*';
				} else if (y <= Y / 2) {
					s[i][y] += '*';
					for(int x = 0; x<(Y/2-y); ++x) s[i][y] += ' ';
					s[i][y] += s[i - 1][y - 1];
					for(int x = 0; x<(Y/2-y)*2; ++x) s[i][y] += ' ';
					s[i][y] += '*';
				} else if (y < Y - 1) {
					s[i][y] += '*';
					for(int x = 0; x<(Y-y-1)*2-1; ++x) s[i][y] += ' ';
					s[i][y] += '*';
				} else {
					s[i][y] += '*';
				}
			}
		}
		Y = Y * 2 + 1;
		X = (X + 1) * 2 + 1;
	}
	for(auto & i : s[n]) cout << i << '\n';
}