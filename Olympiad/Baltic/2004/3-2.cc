#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, i = 0, a, ans[1000001];
	priority_queue<int> pq;
	cin >> n;
    while(++i <= n) {
        cin >> a; a -= i;
        pq.push(a);
		pq.push(a);
		pq.pop();
        ans[i] = pq.top();
    } --i;
    while(--i) if (ans[i] > ans[i + 1]) ans[i] = ans[i + 1];
    while(++i <= n) cout << ans[i] + i << '\n';
}