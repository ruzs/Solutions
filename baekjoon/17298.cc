#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, a[1000001];
	stack<pair<int, int>> st;

	memset(a, -1, sizeof a);
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> x;
		while(st.size() && st.top().first < x) {
			a[st.top().second] = x;
			st.pop();
		}
		st.push({ x, i });
	}
	for(int i =0; i<n; ++i) cout << a[i] << ' ';
}