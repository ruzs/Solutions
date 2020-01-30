#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	priority_queue<int> pq;
	cin >> n;
	long long ans =0;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
		pq.push(a -= i);
        if (pq.size() && pq.top() > a) {
            ans += pq.top() - a;
            pq.pop();
			pq.push(a);
        }
    }
	cout << ans;
}