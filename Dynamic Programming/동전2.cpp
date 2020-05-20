#include<iostream>
#include<algorithm>
using namespace std;

/**
* https://www.acmicpc.net/problem/2294
* Dynamic Programming
*/

int dp[10001];
int value[101];
int n, k;

int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	fill(dp, dp + k + 1, k + 1);

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = value[i]; j <= k; j++) {
			dp[j] = min(dp[j], (dp[j - value[i]] + 1));
		}
	}

	if (dp[k] == k + 1) cout << -1;
	else cout << dp[k];

	return 0;
}
