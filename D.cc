#include <bits/stdc++.h>

using namespace std;

char c[200001];
int k, n[200001];
void solve() {
	scanf("%d %s", &k, c);
	memset(n, -1, sizeof n);
	n[k] = -1;
	c[k] = '>';
	for (int i = k; i >= 0; --i)
		for (int j = 0; j <= k; ++j) {
			if (c[j] == '<' || n[j] != -1) continue;
			if (c[j] == '>') {
				n[j--] = i--;
				while (j >= 0 && c[j] == '<') n[j--] = i--;
			}
		}
	for (int i = 0; i <= k; ++i)
		printf("%d", n[i]), n[i] = -1;
	puts("");
	c[k] = '<';
	for (int i = 0; i < k; ++i)
		for (int j = 0; j <= k; ++j) {
			if (c[j] == '>' || n[j] != -1) continue;
			if (c[j] == '<') {
				n[j--] = i++;
				while (j >= 0 && c[j] == '>') n[j--] = i++;
			}
		}
	for (int i = 0; i <= k; ++i)
		printf("%d", n[i]);
}
int main() {
	int T, t =0; cin >> T;
	while(++t <= T) solve();
}