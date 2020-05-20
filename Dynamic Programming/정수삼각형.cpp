#include<iostream>
#include<algorithm>
using namespace std;

/**
* https://www.acmicpc.net/problem/1932
*/

int dp[501][501];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}
	cout << dp[0][0];

	return 0;
}