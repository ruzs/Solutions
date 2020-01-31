#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	priority_queue<int> o, e;
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> x;
		if (x & 1) o.push(x);
		else e.push(x);
	}
	while(o.size() && e.size()) {
		o.pop(); e.pop();
	}
	if (o.empty() && e.empty()) cout << 0;
	else if (o.size()) {
		o.pop();
		int sum = 0;
		while(o.size()) sum += o.top(), o.pop();
		cout << sum;
	}
	else {
		e.pop();
		int sum = 0;
		while(e.size()) sum += e.top(), e.pop();
		cout << sum;
	}
}