#include<iostream>
#include<algorithm>
using namespace std;

/**
* https://www.acmicpc.net/problem/1463
* Dynamic Programming
*/

int* dp;

int makeOne(int n) {
	if (n == 1) return 0;
	if (dp[n] != -1) return dp[n];

	int m = makeOne(n - 1) + 1;
	if (n % 3 == 0) m = min(m, makeOne(n / 3) + 1);
	if (n % 2 == 0) m = min(m, makeOne(n / 2) + 1);

	dp[n] = m;
	return dp[n];
}

int main() {

	int N;

	cin >> N;		// input
	dp = new int[N+1];
	fill(dp, dp + N + 1, -1);

	cout << makeOne(N);	// output

	return 0;
}
