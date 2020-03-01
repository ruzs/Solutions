#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string a, b;
		cin >> a >> b;
		vector<int> an, bn;
		stack<int> st;
		for(int i =0; i<(int)a.size(); ++i) {
			if (a[i] == '0') st.push(i);
			else an.push_back(i - st.top()), st.pop();
		}
		for(int i =0; i<(int)b.size(); ++i) {
			if (b[i] == '0') st.push(i);
			else bn.push_back(i - st.top()), st.pop();
		}
		sort(an.begin(), an.end());
		sort(bn.begin(), bn.end());
		cout << (an == bn) << '\n';
	}
}