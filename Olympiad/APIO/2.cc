#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int N = 1e5+5;
	int n, k, a[N], nxt[N], pre[N];
	set<pair<int, int>> st;

	cin >> n >> k;
	for(int i =0; i<n; ++i) cin >> a[i];
	for(int i =n-1; i; --i) {
		a[i] -= a[i - 1];
		st.insert({a[i], i});
		nxt[i] = i + 1;
		pre[i] = i - 1;
	}
	a[0] = a[n] = 1e9;

	int ans =0;
	while(k--) {
		auto [m, i] = *st.begin();
		ans += m;
		st.erase(st.begin());
		st.erase({a[pre[i]], pre[i]});
		st.erase({a[nxt[i]], nxt[i]});
		a[i] = a[pre[i]] + a[nxt[i]] - a[i];
		pre[i] = pre[pre[i]];
		nxt[pre[i]] = i;
		nxt[i] = nxt[nxt[i]];
		pre[nxt[i]] = i;
		st.insert({a[i], i});
	}
	cout << ans;
}