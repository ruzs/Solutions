#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
void solve() {
	int n, x, a[100005];
	cin >> n >> x;
	for(int i =0; i<n; ++i) cin >> a[i];
	sort(a, a + n);
	int mxd = 1;
	for(int i =0; i<n; ++i) {
		if (x == a[i]) return cout << "1\n", void();
		if (x % a[i] == 0) mxd = max(mxd, a[i]);
	}
	if (a[n - 1] > x) cout << "2\n";
	else cout << min(x / mxd, x / a[n-1] + (lower_bound(a, a + n, x % a[n-1]) == a + n ? 2 : 1)) << '\n';
=======
bool ispalindrome(const string & s, int l, int r) {
	if (l >= r) return 1;
	if (s[l] == s[r]) return ispalindrome(s, l + 1, r - 1);
	return 0;
>>>>>>> ef72632469cae9f198d75202044b6e0cfa8dcd9e
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

<<<<<<< HEAD
	int T, t =0; cin >> T;
	while(++t <= T) solve();
=======
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	set<string> st;
	for(auto & i : s) cin >> i;

	string ans{}, ans1{}, ans2{};
	for(auto & i : s) {
		string t = i;
		reverse(t.begin(), t.end());
		if (st.count(i)) {
			st.erase(i);
			ans1 += i;
			ans2 = t + ans2;
		}
		else st.insert(t);
	}
	ans += ans1;
	string t = "";
	for(auto & i : st) if (ispalindrome(i, 0, m - 1)) {
		if (t.size() < i.size()) t = i;
	}
	ans += t + ans2;
	cout << ans.size() << '\n' << ans;
>>>>>>> ef72632469cae9f198d75202044b6e0cfa8dcd9e
}