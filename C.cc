#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
long long f(long long a) {
	if (a <= 2) return a;
	return a * (a - 1) / 2;
=======
struct customer {
	int t, l, h;
} a[101];

int n, m;
bool go(int i, int m) {
	if (a[i].l > m || a[i].h < m) return 0;
	if (i == n) return 1;
	int d = a[i + 1].t - a[i].t;
	if (go(i + 1, m + d)) 
	return 0;
}
void solve() {
	cin >> n >> m;
	for(int i =1; i<=n; ++i) cin >> a[i].t >> a[i].l >> a[i].h;
	
>>>>>>> ef72632469cae9f198d75202044b6e0cfa8dcd9e
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

<<<<<<< HEAD
	char s[100005];
	long long ab[26]{};
	cin >> s;
	long long ans = 1, cnt = 0;
	for(int i =0; s[i]; ++i) {
		ab[s[i] - 'a']++;
		cnt++;
		if (s[i] != s[i + 1]) {
			ans = max(ans * f(cnt), f(ab[s[i] - 'a']));
			cnt = 0;
		}
	}
	cout << ans;
=======
	int T, t =0; cin >> T;
	while(++t <= T) solve();
>>>>>>> ef72632469cae9f198d75202044b6e0cfa8dcd9e
}