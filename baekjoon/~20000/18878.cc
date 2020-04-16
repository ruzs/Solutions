#include <bits/stdc++.h>

using namespace std;

int n, m;
int f[100005], s[100005];
int mp[100005];
stack<int> st;

int pos(int x, int i) {
	if (!mp[x]) {
		mp[x] = i;
		return 1;
	} else {
		int j = mp[x];
		if (j < i) return 0;
		mp[x] = i;
		if (x == s[j]) return 0;
		return pos(s[j], j);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i =1; i<=n; ++i) {
		cin >> f[i] >> s[i];
	}
	int cnt = 0;
	for(int i =n; i; --i) {
		st.push(cnt += pos(f[i], i));
	}
	while(st.size()) {
		cout << st.top() << '\n';
		st.pop();
	}
}