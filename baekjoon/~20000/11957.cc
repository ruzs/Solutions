#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const double eps = 1e-6;
	int n;
	cin >> n;
	vector<double> a(n + 1);
	for(int i =1; i<=n; ++i) cin >> a[i];
	string s;
	cin >> s;
	string r = "";
	stack<double> st;
	for(char c : s) {
		if (c == '(') st.push(-1);
		else if (c == ')') {
			double tmp = st.top();
			st.pop();
			while(st.size() && fabs(st.top() - -1) > eps) {
				if (fabs(st.top() - -2) < eps) {
					st.pop();
					tmp += st.top();
					st.pop();
				} else if (fabs(st.top() - -3) < eps) {
					st.pop();
					tmp = 1 / (1 / tmp + 1 / st.top());
					st.pop();
				}
			}
			st.pop();
			st.push(tmp);
		}
		else if (c == '-') {
			st.push(-2);
		}
		else if (c == '|') {
			st.push(-3);
		}
		else if (isdigit(c)) {
			st.push(a[c & 15]);
		}
	}
	cout << setprecision(20) << st.top();
}