/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>

using namespace std;

int Answer;

struct fenwick {
	const int N = 20000005;
	int a[20000005];
	void init() {
		memset(a, 0, sizeof a);
	}
	void add(int p, int x) {
		do a[p] += x;
		while ((p += p & -p) < N);
	}
	int sum(int p) {
		int r = 0;
		do r += a[p];
		while (p -= p & -p);
		return r;
	}
	int find_nth(int nth) {
		int x = 0, j = 2e7;
		while (j /= 2) while (sum(x + j) <= nth) x += j;
		return x + 1;
	}
} fw;


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		int n, k, Q;
		cin >> n >> k >> Q;

		fw.init();
		vector<int> a(n + 1), p = {0}, b = {0};
		for(int i =1; i<=n; ++i) {
			cin >> a[i];
			p.push_back(p.back() + a[i]);
		}
		for(int i = 1; i + k - 1 <= n; ++i) {
			int x = p[i + k - 1] - p[i - 1];
			fw.add(x, 1);
			b.push_back(x);
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << fw.find_nth((n - k + 1) / 2) << ' ';
		while (Q--) {
			int x, y;
			cin >> x >> y;
			int diff = y - a[x];
			a[x] = y;
			for(int i = max(1, x - k + 1); i <= x && i + k - 1 <= n; ++i) {
				fw.add(b[i], -1);
				b[i] += diff;
				fw.add(b[i], 1);
			}
			cout << fw.find_nth((n - k + 1) / 2) << ' ';
		}
		cout << endl;

	}

	return 0;//Your program should return 0 on normal termination.
}