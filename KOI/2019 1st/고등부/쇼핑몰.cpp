#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n, m, id, w;
long long r, ans;
struct casher{
	int d, n, id;
	bool operator < (const casher& b) const {
		return d == b.d ? n > b.n : d > b.d;
	}
};
priority_queue<casher> pq;
stack<casher> st;
void exit() {
	while(st.size()) {
		ans += ++r * st.top().id;
		st.pop();
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i =1; m-- && n--; ++i){
		cin >> id >> w;
		pq.push({ w, i, id });
	}
	while(n-- > 0){
		cin >> id >> w;
		auto top = pq.top(); pq.pop();
		if (st.size() && top.d != st.top().d) exit();
		st.push(top);
		top.d += w;
		top.id = id;
		pq.push(top);
	}
	while(pq.size()) {
		auto top = pq.top(); pq.pop();
		if (st.size() && top.d != st.top().d) exit();
		st.push(top);
	}
	exit();
	cout << ans;
}
