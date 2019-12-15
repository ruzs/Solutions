#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a;
stack<int> st;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while(n--){
		cin >> a;
		while(st.size() && st.top() <= a) st.pop();
		st.push(a);
	}
	cout << st.size();
}
