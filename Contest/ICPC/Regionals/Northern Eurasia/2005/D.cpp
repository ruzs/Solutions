#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int a[9][5];
bool chk[5][5][5][5][5][5][5][5][5];
double d[5][5][5][5][5][5][5][5][5];
int nCr(int n, int r) {
	int ret = 1;
	for(int i =1; i<=n; ++i) ret *= i;
	for(int i =1; i<=r; ++i) ret /= i;
	return ret;
}
double dp(vector<int> & x) {
	if (!x[0] && !x[1] && !x[2] && !x[3] && !x[4] && !x[5] && !x[6] && !x[7] && !x[8]) return 1.0;
	double & ref = d[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]][x[8]];
	if (chk[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]][x[8]]) return ref;
	chk[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]][x[8]] = 1;
	int cnt = 0;
	for(int i =0; i<9; ++i) {
		for(int j =i + 1; j<9; ++j) {
			if (x[i] && x[j] && a[i][x[i]] == a[j][x[j]]) {
				x[i]--;
				x[j]--;
				ref += dp(x);
				x[i]++;
				x[j]++;
				cnt++;
			}
		}
	}
	if (!cnt) return ref = 0.0;
	return ref /= (double)cnt;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i =0; i<9; ++i) {
		for(int j =1; j<=4; ++j) {
			char s[3];
			cin >> s;
			switch(s[0]) {
				case 'A' : a[i][j] = 1; break;
				case 'K' : a[i][j] = 2; break;
				case 'Q' : a[i][j] = 3; break;
				case 'J' : a[i][j] = 4; break;
				case 'T' : a[i][j] = 5; break;
				default : a[i][j] = s[0] & 15; break;
			}
		}
	}
	vector<int> init(9, 4);
	cout << dp(init);
}
