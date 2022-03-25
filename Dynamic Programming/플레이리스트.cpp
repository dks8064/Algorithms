#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007;

int N, M, P;
long long dp[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M >> P;
	dp[0][0] = 1;
	for (int i = 1; i <= P; i++) {
		for (int j = 0; j <= N; j++) {
			if (j > 0) dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1] * (N - j + 1))) % MOD;
			if (j > M)dp[i][j] = (dp[i][j] + (dp[i - 1][j] * (j - M))) % MOD;
		}
	}

	cout << dp[P][N];

	return 0;
}