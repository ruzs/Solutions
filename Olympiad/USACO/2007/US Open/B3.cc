#include <bits/stdc++.h>

using namespace std;

int n, l, cnt = 0;
int myf(int cnt, int deep) {
	if (cnt == 0) return 0;
	if (cnt % 10 == l) return deep;
	return myf(cnt / 10, deep * 10);
}
int main() {
	scanf("%d%d", &n, &l);
	while (n--) {
		cnt += myf(cnt + 1, 1) + 1;
	}
	printf("%d", cnt);
}