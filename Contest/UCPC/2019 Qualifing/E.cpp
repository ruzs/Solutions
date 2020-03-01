#include<bits/stdc++.h>
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#ifdef _CONSOLE
#define tio freopen("input.txt","r",stdin)
#else
#define tio (void)0
#endif
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define MAX 300000
int n, m, a, b, match;
int d[MAX + 2], l[MAX + 2][20], L[MAX + 2][20], r[MAX + 2][20], R[MAX + 2][20];
char s[MAX + 2];
stack<int> st;

int main() {
	fio; tio;
	cin >> n >> m >> s + 1;
	s[0] = '('; s[n + 1] = ')';
	memset(L[0], 64, sizeof L[0]);
	memset(R[0], 64, sizeof R[0]);
	memset(L[n + 1], 64, sizeof L[n + 1]);
	memset(R[n + 1], 64, sizeof R[n + 1]);
	fill(r[n + 1], r[n + 1] + 20, n + 1);

	st.push(0);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == ')') {
			match = st.top(), st.pop();
			l[i][0] = st.top();
			L[i][0] = L[match][0] + (match + 1 == i ? 1 : 2);
			d[i] = d[match] + (match + 1 == i ? 1 : 2);
		}
		else {
			l[i][0] = st.top();
			if (s[i] == '(') st.push(i);
			L[i][0] = s[i - 1] == '(' ? 1 : L[i - 1][0] + 1;
			d[i] = d[i - 1] + 1;
		}
	}
	st.pop(); st.push(n + 1);
	for (int i = n; i >= 1; --i) {
		if (s[i] == '(') {
			match = st.top(), st.pop();
			r[i][0] = st.top();
			R[i][0] = R[match][0] + (match - 1 == i ? 1 : 2);
		}
		else {
			r[i][0] = st.top();
			if (s[i] == ')') st.push(i);
			R[i][0] = s[i + 1] == ')' ? 1 : R[i + 1][0] + 1;
		}
	}
	st.pop();

	for (int i = 1; i <= n; ++i) {
		L[i][0] = min(L[i][0], R[i][0] + 2);
		R[i][0] = min(R[i][0], L[i][0] + 2);
	}
	for (int j = 1; j < 20; ++j) {
		for (int i = 1; i <= n; ++i) {
			l[i][j] = l[l[i][j - 1]][j - 1];
			r[i][j] = r[r[i][j - 1]][j - 1];
			L[i][j] = min({
				l[i][j - 1] ? INT_MAX : L[i][j - 1],
				L[i][j - 1] + L[l[i][j - 1]][j - 1],
				R[i][j - 1] + L[r[i][j - 1]][j - 1] });
			R[i][j] = min({
				l[i][j - 1] ? INT_MAX : R[i][j - 1],
				L[i][j - 1] + R[l[i][j - 1]][j - 1],
				R[i][j - 1] + R[r[i][j - 1]][j - 1] });
			L[i][j] = min(L[i][j], R[i][j] + 2);
			R[i][j] = min(R[i][j], L[i][j] + 2);
		}
	}

	while (m--) {
		cin >> a >> b;
		if (a > b) swap(a, b);

		int hull = b;
		for (int j = 19; j >= 0; --j) {
			if (a <= l[hull][j]) hull = l[hull][j];
		}
		hull = l[hull][0];

		int al = a, ar = a, bl = b, br = b;
		int AL = 0, AR = 0, BL = 0, BR = 0, NL, NR;

		for (int j = 19; j >= 0; --j) {
			if (hull < l[al][j]) {
				NL = min(AL + L[al][j], AR + L[ar][j]);
				NR = min(AL + R[al][j], AR + R[ar][j]);
				AL = NL; AR = NR;
				al = l[al][j]; ar = r[ar][j];
			}
			if (hull < l[bl][j]) {
				NL = min(BL + L[bl][j], BR + L[br][j]);
				NR = min(BL + R[bl][j], BR + R[br][j]);
				BL = NL; BR = NR;
				bl = l[bl][j]; br = r[br][j];
			}
		}
		if (l[al][0] == 0) cout << AR + BL + d[bl] - d[ar] << '\n';
		else cout << min(AL + L[al][0] + BR + R[br][0] + 2, AR + BL + d[bl] - d[ar]) << '\n';
	}
}
