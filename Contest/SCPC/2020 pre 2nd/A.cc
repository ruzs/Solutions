/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>

using namespace std;

long long Answer;

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

		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(int & i : a) cin >> i;
		for(int & i : b) cin >> i;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		vector<array<long long, 3>> d(n);
		d[0][0] = abs(a[0] - b[0]);
		if (n >= 2) d[0][1] = abs(a[1] - b[0]);
		d[0][2] = 1e9;
		for(int i =1; i<n; ++i) {
			int x = abs(a[i] - b[i]);
			d[i][0] = d[i - 1][0] + x;
			if (i + 1 < n) d[i][1] = min(d[i - 1][0], d[i - 1][1]) + abs(a[i + 1] - b[i]);
			d[i][2] = min({d[i - 1][0], d[i - 1][1], d[i - 1][2] + x});
		}
		Answer = min(d[n - 1][0], d[n - 1][2]);

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		
		d = vector<array<long long, 3>>(n);
		d[0][0] = abs(a[0] - b[0]);
		if (n >= 2) d[0][1] = abs(a[1] - b[0]);
		d[0][2] = 1e9;
		for(int i =1; i<n; ++i) {
			int x = abs(a[i] - b[i]);
			d[i][0] = d[i - 1][0] + x;
			if (i + 1 < n) d[i][1] = min(d[i - 1][0], d[i - 1][1]) + abs(a[i + 1] - b[i]);
			d[i][2] = min({d[i - 1][0], d[i - 1][1], d[i - 1][2] + x});
		}
		Answer = min(Answer, min(d[n - 1][0], d[n - 1][2]));

		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}