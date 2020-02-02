#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	deque<int> dq;
	int n, m, k;
	cin >> n >> m >> k;
	dq.resize(n);
	for(int & i : dq) cin >> i;
	for(int i =1; i<m; ++i) {
		if (k) {
			if (dq.front() > dq.back()) dq.pop_back();
			else if (dq.front() < dq.back()) dq.pop_front();
			else {
				if (dq.size() > 2 && dq[1] > dq[dq.size() - 2])
					dq.pop_back();
				else dq.pop_front();
			}
			k--;
		}
		else {
			if (dq.front() < dq.back()) dq.pop_back();
			else dq.pop_front();
		}
	}
	cout << max(dq.front(), dq.back()) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int T; cin >> T;
	while(T--) solve();
}