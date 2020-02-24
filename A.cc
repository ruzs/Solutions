#include <bits/stdc++.h>

using namespace std;

int w[][3] = {{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,1,1}};
int go(int a, int b, int c, int n) {
	if (a < 0 || b < 0 || c < 0) return -1e9;
	if (n == 7) return 0;
	int res = 0;
	for(int i =n; i<7; ++i) {
		res = max(res, go(a - w[i][0], b - w[i][1], c - w[i][2], i + 1) + 1);
	}
	return res;
}
void test() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << go(a, b, c, 0) << '\n';
}
int main() {
	int t;
	cin >> t;
	while(t--) test();
}